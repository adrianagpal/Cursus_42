from pydantic import BaseModel, Field, ConfigDict, ValidationError
from typing import Optional, Annotated
from datetime import datetime

Percentage = Annotated[float, Field(ge=0, le=100)]

class SpaceStation(BaseModel):

    model_config = ConfigDict(validate_assignment=True)

    station_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=1, max_length=50)
    crew_size: int = Field(ge=1, le=20)
    power_level: Percentage
    oxygen_level: Percentage
    last_maintenance: Optional[datetime] = None
    is_operational: bool = Field(default=True)
    notes: str | None = Field(default=None, max_length=200)


def main() -> None:
    print("Space Station Data Validation")
    print("========================================")

    try:
        valid_station = SpaceStation(
            station_id = "ISS001",
            name = "International Space Station",
            crew_size = 6,
            power_level = 85.5,
            oxygen_level = 92.3,
            last_maintenance = "2025-04-06",
            is_operational = False
        )

        print("Valid station created:")
        print(f"ID: {valid_station.station_id}\n"
              f"Name: {valid_station.name}\n"
              f"Crew: {valid_station.crew_size} people\n"
              f"Power: {valid_station.power_level}%\n"
              f"Oxygen: {valid_station.oxygen_level}%\n"
              f"Status: {'Operational' if valid_station.is_operational else 'Not operational'}\n"
              f"Date: {valid_station.last_maintenance}"
        )

    except ValidationError as e:
        for err in e.errors():
            print(f"{err['loc'][0]}: {err['msg']}")
    
    print("========================================")
    print("Expected validation error:")
    try:
        invalid_station = SpaceStation(
            station_id = "ISS001",
            name = "International Space Station",
            crew_size = 40,
            power_level = 140,
            oxygen_level = 92.3
        )
        
    except ValidationError as e:
        for err in e.errors():
            print(f"{err['loc'][0]}: {err['msg']}")



if __name__ == "__main__":
    main()