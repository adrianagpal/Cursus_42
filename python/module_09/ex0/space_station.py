from pydantic import BaseModel, Field, ValidationError
from datetime import datetime


class SpaceStation(BaseModel):
    station_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=1, max_length=50)
    crew_size: int = Field(ge=1, le=20)
    power_level: float = Field(ge=0, le=100)
    oxygen_level: float = Field(ge=0, le=100)
    last_maintenance: datetime
    is_operational: bool = Field(default=True)
    notes: str | None = Field(default=None, max_length=200)


def main() -> None:
    print("Space Station Data Validation")
    print("========================================")

    try:
        valid_station = SpaceStation(
            station_id="ISS001",
            name="International Space Station",
            crew_size=6,
            power_level=85.5,
            oxygen_level=92.3,
            last_maintenance=datetime(2025, 6, 20, 16, 31, 34, 273244)
        )
        status = (
            'Operational'
            if valid_station.is_operational
            else 'Not operational'
        )

        print("Valid station created:")
        print(f"ID: {valid_station.station_id}\n"
              f"Name: {valid_station.name}\n"
              f"Crew: {valid_station.crew_size} people\n"
              f"Power: {valid_station.power_level}%\n"
              f"Oxygen: {valid_station.oxygen_level}%\n"
              f"Status: {status}\n")

    except ValidationError as e:
        for err in e.errors():
            print(f"{err['loc'][0]}: {err['msg']}")

    print("========================================")
    print("Expected validation error:")
    try:
        SpaceStation(
            station_id="ISS001",
            name="International Space Station",
            crew_size=40,
            power_level=85.5,
            oxygen_level=92.3,
            last_maintenance=datetime.now()
        )

    except ValidationError as e:
        for err in e.errors():
            print(f"{err['loc'][0]}: {err['msg']}")


if __name__ == "__main__":
    main()
