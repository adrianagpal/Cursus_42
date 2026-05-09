from pydantic import BaseModel, Field, ConfigDict, ValidationError, model_validator
from typing import Optional, Annotated
from datetime import datetime
from enum import IntEnum


class Rank(IntEnum):
    cadet = 1 
    officer = 2
    lieutenant = 3
    captain = 4
    commander = 5


class CrewMember(BaseModel):
    member_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=2, max_length=50)
    rank: Rank
    age: int = Field(ge=18, le=80)
    specialization: str = Field(min_length=3, max_length=30)
    years_experience: int = Field(ge=0, le=50)
    is_active: bool = Field(default=True)


class SpaceMission(BaseModel):
    mission_id: str = Field(min_length=5, max_length=15)
    mission_name: str = Field(min_length=3, max_length=100)
    destination: str = Field(min_length=3, max_length=50)
    launch_date: Optional[datetime] = None
    duration_days: int = Field(ge=1, le=3650)
    crew: list[CrewMember] = Field(min_length=1, max_length=12)
    mission_status: str = Field(default="planned")
    budget_millions: float = Field(ge=1, le=10000)

    @model_validator(mode='after')
    def validate_mission(self):
        if not self.mission_id.startswith('M'):
            raise ValueError("Mission ID must start with 'M'")

        high_rank = [member for member in self.crew if member.rank > 3]
        exp_crew = [member for member in self.crew if member.years_experience > 5]
        inactive_crew = [member for member in self.crew if not member.is_active]

        if not high_rank:
            raise ValueError("Must have at least one Commander or Captain")
            
        if len(exp_crew)/len(self.crew) < 0.5:
            raise ValueError("Long missions (> 365 days) need 50% experienced crew (5+ years)")
        
        if inactive_crew:
            raise ValueError("All crew members must be active")
        
        return self
            

def main() -> None:
    print("Space Mission Crew Validation")
    print("=========================================")

    try:
        sarah = CrewMember(
            member_id = 'member1',
            name = 'Sarah Connor',
            rank = 5,
            age = 45,
            specialization = 'Mission Command',
            years_experience = 10
        )

        john = CrewMember(
            member_id = 'member2',
            name = 'John Smith',
            rank = 3,
            age = 40,
            specialization = 'Navigation',
            years_experience = 10
        )

        alice = CrewMember(
            member_id = 'member3',
            name = 'Alice Johnson',
            rank = 2,
            age = 35,
            specialization = 'Engineering',
            years_experience = 8
        )        

        valid_mission = SpaceMission(
            mission_name = 'Mars Colony Establishment',
            mission_id = 'M2024_MARS',
            destination = 'Mars',
            duration_days = 900,
            budget_millions = 2500,
            crew = [sarah, john, alice]
        )

        print("Valid mission created:")
        print(f"Mission: {valid_mission.mission_name}\n"
              f"ID: {valid_mission.mission_id}\n"
              f"Destination: {valid_mission.destination}\n"
              f"Duration: {valid_mission.duration_days} days\n"
              f"Budget: ${valid_mission.budget_millions:.1f}M\n"
              f"Crew size: {len(valid_mission.crew)}"
        )
        if valid_mission.crew:
            print("Crew members:")
            for member in valid_mission.crew:
                print(f"- {member.name} ({member.rank}) - {member.specialization}")

    except ValidationError as e:
        for err in e.errors():
            print(f"{err['loc']}: {err['msg']}")


if __name__ == "__main__":
    main()

