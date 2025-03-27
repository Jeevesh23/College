import math

if __name__=="__main__":
  print("Program to convert radians to degrees and vice versa:")
  while True:
    c = input("Enter r to convert to radians, d to convert to degrees:")
    if c.upper() == "R":
      deg = float(input("Enter degrees:"))
      r = math.radians(deg)
      print("The radian value for {} = {} rad".format(deg,r))
    elif c.upper() == "D":
      rad = float(input("Enter radians:"))
      deg = math.degrees(rad)
      print("The degree value for {} = {} deg".format(rad,deg))
    choice = input("Enter yes to continue, anything else to break:")
    if choice[0].upper() != "Y":
      print("Thank you for using the angle unit convertor")
      break
