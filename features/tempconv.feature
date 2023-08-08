Feature: Application should be able to convert from Celsius to Fahrenheit

    Scenario Outline: Should be able to convert from 0C to 32F
        Given an instance of the converter class
        When the Celsius value is <c_value>
        Then it should return <f_value>

        Examples:
            | c_value | f_value |
            | 0       | 32      |
            | 100     | 212     |
            | -40     | -40     |