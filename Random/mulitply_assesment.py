'''
You work in an automated factory and your objective is to write the method that will dispatch the packages to the correct stack, according to their volume and mass.

A package is bulky if its volume (Width x Height x Length) is greater than or equal to 1,000,000 cm³ or when one of its dimension is greater or equal than 150 cm.

A package is heavy when its mass is greater or equal than 20 kg.

You must dispatch the packages in the following stacks:

          STANDARD: standard packages (those which are not bulky nor heavy) can be handled normally.

          SPECIAL: packages that are either heavy or bulky can't be handled automatically.

          REJECTED: packages that are both heavy and bulky are rejected.
'''

Standard = []
Special = []
Rejected = []


def solve(width, height, length, mass):
    package = (width, height, length, mass)

    isBulky = False
    isHeavy = False

    if(max(width, length, height) >= 150 or width * height * length >= 1000000):
        isBulky = True

    if(mass >= 20):
        isHeavy = True

    if isBulky and isHeavy:
        Rejected.append(package)
        return "REJECTED"
    
    if isBulky or isHeavy:
        Special.append(package)
        return "SPECIAL"
    
    Standard.append(package)
    return "STANDARD"


if __name__ == "__main__":
    packages = [(160, 70, 70, 10), (120, 100, 100, 10), (90, 90, 118, 10), (120, 100, 50, 30), (80, 110, 80, 70), (70, 80, 90, 10), (100, 120, 60, 19), (150, 70, 70, 10), (120, 100, 100, 10), (90, 90, 118, 10), (120, 100, 110, 20), (80, 110, 80, 70), (70, 80, 90, 10), (100, 150, 60, 30)]

    for package in packages:
        width, height, length, mass = package
        print(f"Package ({width}, {height}, {length}, {mass}) is {solve(width, height, length, mass)}")

    # print packages category-wise
    # print(Standard)
    # print(Special)
    # print(Rejected)