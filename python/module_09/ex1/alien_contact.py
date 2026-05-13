from pydantic import BaseModel, Field, ValidationError, model_validator
from datetime import datetime
from typing_extensions import Self
from enum import Enum


class ContactType(str, Enum):
    RADIO = 'radio'
    VISUAL = 'visual'
    PHYSICAL = 'physical'
    TELEPATHIC = 'telepathic'


class AlienContact(BaseModel):
    contact_id: str = Field(min_length=5, max_length=15)
    timestamp: datetime
    location: str = Field(min_length=3, max_length=100)
    contact_type: ContactType
    signal_strength: float = Field(ge=0, le=10)
    duration_minutes: int = Field(ge=1, le=1440)
    witness_count: int = Field(ge=1, le=100)
    message_received: str | None = Field(default=None, max_length=500)
    is_verified: bool = Field(default=False)

    @model_validator(mode='after')
    def validate_model(self) -> Self:
        if not self.contact_id.startswith('AC'):
            raise ValueError("Contact ID must start with 'AC'")

        if self.contact_type.value == 'physical' and not self.is_verified:
            raise ValueError("Physical contact reports must be verified")

        if self.contact_type.value == 'telepathic' and self.witness_count < 3:
            raise ValueError("Telepathic contact "
                             "requires at least 3 witnesses")

        if self.signal_strength > 7 and not self.message_received:
            raise ValueError("Strong signals (> 7.0) "
                             "should include received messages")

        return self


def main() -> None:
    print("Alien Contact Log Validation")
    print("======================================")

    try:
        valid_contact = AlienContact(
            contact_id='AC_2024_001',
            contact_type=ContactType.RADIO,
            location='Area 51, Nevada',
            signal_strength=8.5,
            duration_minutes=45,
            witness_count=5,
            message_received='Greetings from Zeta Reticuli',
            is_verified=False,
            timestamp=datetime(2025, 4, 20, 14, 39, 56)
        )

        print("Valid contact report:")
        print(
            f"ID: {valid_contact.contact_id}\n"
            f"Type: {valid_contact.contact_type}\n"
            f"Location: {valid_contact.location}\n"
            f"Signal: {valid_contact.signal_strength}/10\n"
            f"Duration: {valid_contact.duration_minutes} minutes\n"
            f"Witnesses: {valid_contact.witness_count}\n"
            f"Message: {valid_contact.message_received}\n"
        )

    except ValidationError as e:
        for err in e.errors():
            print(err['msg'].replace("Value error, ", ""))

    print("======================================")
    print("Expected validation error:")
    try:
        AlienContact(
            contact_id='AC_2024_001',
            contact_type=ContactType.PHYSICAL,
            location='Area 51, Nevada',
            signal_strength=8.5,
            duration_minutes=45,
            witness_count=2,
            message_received='Greetings from Zeta Reticuli',
            timestamp=datetime(2025, 4, 20, 16, 31, 34)
        )

    except ValidationError as e:
        for err in e.errors():
            print(err['msg'].replace("Value error, ", ""))


if __name__ == "__main__":
    main()
