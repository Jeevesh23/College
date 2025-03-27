def yes_no(question):
    """Asks a yes or no question and returns True/False based on the answer."""
    answer = input(question + " [Y/N]: ").lower()
    return answer == "y"


def get_category_problems():
    """Asks the user if they have problems in each category and returns a dictionary."""
    categories = {"engine": False, "tires": False, "lights": False, "brakes": False}
    for category in categories:
        categories[category] = yes_no(f"Are you having problems with your {category}?")
    return categories


def engine_problems():
    """Asks specific questions about engine problems."""
    problems = {"starting": False, "performance": False, "leaking": False}
    print("Engine problems:")
    for problem in problems:
        problems[problem] = yes_no(f"  - Difficulty {problem}?")
    return problems


def tire_problems():
    """Asks specific questions about tire problems."""
    problems = {"flat": False, "worn": False, "pressure": False}
    print("Tire problems:")
    for problem in problems:
        problems[problem] = yes_no(f"  - Do you have a {problem} tire?")
    return problems


def light_problems():
    """Asks specific questions about light problems."""
    problems = {"headlight": False, "taillight": False, "indicator": False}
    print("Light problems:")
    for problem in problems:
        problems[problem] = yes_no(f"  - Is your {problem} not working?")
    return problems


def brake_problems():
    """Asks specific questions about brake problems."""
    problems = {"squeaking": False, "weak": False, "leaking": False}
    print("Brake problems:")
    for problem in problems:
        problems[problem] = yes_no(f"  - Are your brakes {problem}?")
    return problems


def diagnose_problem(category_problems):
    """Analyzes user input and provides potential problems based on categories."""
    if category_problems["engine"]:
        engine_issues = engine_problems()
        print("\nPotential engine problems:")
        if engine_issues["starting"]:
            print("  - Starter motor or battery issue")
        if engine_issues["performance"]:
            print("  - Carburetor or fuel injection issue")
        if engine_issues["leaking"]:
            print("  - Oil or coolant leak")
    if category_problems["tires"]:
        tire_issues = tire_problems()
        print("\nPotential tire problems:")
        if tire_issues["flat"]:
            print("  - Fix the puncture or replace the tire")
        if tire_issues["worn"]:
            print("  - Replace the tires")
        if tire_issues["pressure"]:
            print("  - Adjust tire pressure")
    if category_problems["lights"]:
        light_issues = light_problems()
        print("\nPotential light problems:")
        if light_issues["headlight"]:
            print("  - Check headlight bulb or fuse")
        if light_issues["taillight"] or light_issues["indicator"]:
            print("  - Check taillight/indicator bulb or fuse")
    if category_problems["brakes"]:
        brake_issues = brake_problems()
        print("\nPotential brake problems:")
        if brake_issues["squeaking"]:
            print("  - Worn brake pads or need lubrication")
        if brake_issues["weak"]:
            print("  - Check brake fluid level or worn brake pads")
        if brake_issues["leaking"]:
            print("  - Brake fluid leak, consult a mechanic immediately")


def main():
    """Executes the expert system."""
    category_problems = get_category_problems()
    diagnose_problem(category_problems)


if __name__ == "__main__":
    main()
