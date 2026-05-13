from pydantic import BaseModel, Field, ValidationError, model_validator
from datetime import datetime
from typing_extensions import Self
from enum import IntEnum


class Rank(IntEnum):
    CADET = 1
    OFFICER = 2
    LIEUTENANT = 3
    CAPTAIN = 4
    COMMANDER = 5


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
    launch_date: datetime
    duration_days: int = Field(ge=1, le=3650)
    crew: list[CrewMember] = Field(min_length=1, max_length=12)
    mission_status: str = Field(default="planned")
    budget_millions: float = Field(ge=1, le=10000)

    @model_validator(mode='after')
    def validate_mission(self) -> Self:
        if not self.mission_id.startswith('M'):
            raise ValueError("Mission ID must start with 'M'")

        high_rank = [member for member in self.crew if member.rank > 3]

        if not high_rank:
            raise ValueError("Must have at least one Commander or Captain")

        exp_crew = [member for member in self.crew
                    if member.years_experience > 5]

        if len(exp_crew) / len(self.crew) < 0.5:
            raise ValueError("Long missions (> 365 days) need "
                             "50% experienced crew (5+ years)")

        inactive_crew = [member for member in self.crew
                         if not member.is_active]

        if inactive_crew:
            raise ValueError("All crew members must be active")

        return self


def main() -> None:
    print("Space Mission Crew Validation")
    print("=========================================")

    try:
        sarah = CrewMember(
            member_id='member1',
            name='Sarah Connor',
            rank=Rank.COMMANDER,
            age=45,
            specialization='Mission Command',
            years_experience=10
        )

        john = CrewMember(
            member_id='member2',
            name='John Smith',
            rank=Rank.LIEUTENANT,
            age=40,
            specialization='Navigation',
            years_experience=10
        )

        alice = CrewMember(
            member_id='member3',
            name='Alice Johnson',
            rank=Rank.OFFICER,
            age=35,
            specialization='Engineering',
            years_experience=8
        )

        valid_mission = SpaceMission(
            mission_name='Mars Colony Establishment',
            mission_id='M2024_MARS',
            destination='Mars',
            duration_days=900,
            budget_millions=2500,
            crew=[sarah, john, alice],
            launch_date=datetime.now()
        )

        print("Valid mission created:")
        print(
            f"Mission: {valid_mission.mission_name}\n"
            f"ID: {valid_mission.mission_id}\n"
            f"Destination: {valid_mission.destination}\n"
            f"Duration: {valid_mission.duration_days} days\n"
            f"Budget: ${valid_mission.budget_millions:.1f}M\n"
            f"Crew size: {len(valid_mission.crew)}"
        )
        if valid_mission.crew:
            print("Crew members:")
            for member in valid_mission.crew:
                print(f"- {member.name} ({member.rank}) - "
                      f"{member.specialization}")

    except ValidationError as e:
        for err in e.errors():
            print(err['msg'].replace("Value error, ", ""))

    print()
    print("=========================================")
    print("Expected validation error:")

    try:
        bella = CrewMember(
            member_id='member1',
            name='Bella Swan',
            rank=Rank.OFFICER,
            age=45,
            specialization='Engineering',
            years_experience=10
        )

        SpaceMission(
            mission_name='Mars Colony Establishment',
            mission_id='M2024_MARS',
            destination='Mars',
            duration_days=900,
            budget_millions=2500,
            crew=[bella],
            launch_date=datetime.now()
        )
    except ValidationError as e:
        for err in e.errors():
            print(err['msg'].replace("Value error, ", ""))


if __name__ == "__main__":
    main()
