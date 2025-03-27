import numpy as test
import matplotlib.pyplot as plt

def get_array():
    n = int(input("Enter size of vector: "))
    print("Enter elements of vector: ")
    inputs = list(map(int, input().split()))
    arr = []
    k = 0
    for i in range(n):
        elem = inputs[k]
        arr.append(elem)
        k += 1
    arr = test.array(arr)
    return arr

while True:  
    print("\nMAIN MENU")
    print("1. Create a Numpy array filled with all ones")
    print("2. Find the number of occurrences of a sequence in a NumPy array")
    print("3. Interchange two axes of an array")
    print("4. Trim the leading and/or trailing zeros from a 1-D array")
    print("5. Reverse a numpy array")
    print("6. Make a NumPy array read-only")
    print("7. Replace NumPy array elements that doesn’t satisfy the given condition")
    print("8. Remove columns in Numpy array that contains non-numeric values")
    print("9. Create a Numpy array with random values")
    print("10. Get the n-largest values of an array using Numpy")
    print("11. Get the floor, ceiling and truncated values of the elements of a numpy array")
    print("12. Evaluate Einstein’s summation convention of two multidimensional NumPy arrays")
    print("13. Compute the variance of the NumPy array")
    print("14. Compute the standard deviation of the NumPy array")
    print("15. Compute pearson product-moment correlation coefficients of two given NumPy arrays")
    print("16. Calculate the mean across dimension in a 2D NumPy array")
    print("17. Define a polynomial function. Add, subtract, multiply and divide one polynomial to another using NumPy")
    print("18. Save a NumPy array to a text file?")
    print("19. Load data from a text file")
    print("20. Plot line graph from NumPy array")
    print("21. Create Histogram using NumPy") 
    print("22. Exit")  
    choice = int(input("Enter the Choice:"))  
  
    if choice == 1:  
        n=int(input("Enter the number of ones:"))
        a = test.ones(n, dtype = int)
        print("Array a : \n", a)
      
    elif choice == 2:  
        arr=test.array[[2, 3, 4],
                       [4, 6, 2, 3],
                       [9, 10, 2, 3]]
        output = repr(arr).count("2, 3")
        print(output)
  
    elif choice == 3:  
        x = test.array([[1,2,3]])
        print(x)
        y =  test.swapaxes(x,0,1)
        print(y)                
    
    elif choice == 4:  
        arr1 = test.array((0, 0, 0, 0, 1, 5, 7, 0, 6, 2, 9, 0, 10, 0, 0))
        arr2 = test.trim_zeros(arr1)
        print(arr2)
              
    elif choice == 5:  
        arr1 = get_array
        arr2 = test.flip(arr1)
        print("final array", str(arr2))

    #elif choice == 6:  
        
            
    #elif choice == 7:  
        

    # elif choice == 8:
         

    elif choice == 9:
        n=int(input("Enter the size for the array - "))
        m=input("Enter the datatype of the array - ")
        a = test.empty(n, dtype = m) 
        print("Array a : \n", a) 
        
    elif choice == 10:
        arr = get_array()        
        print("Given array:", arr)
        sorted_index_array = test.argsort(arr)
        sorted_array = arr[sorted_index_array]
        print("Sorted array:", sorted_array)
        n=int(input("Enter the number of largest values required - "))
        rslt = sorted_array[-n : ]
        print("{} largest value:".format(n),rslt) 

    elif choice == 11:
        arr = get_array()
        print(arr)
        floor_values = test.floor(arr)
        print("\nFloor values : \n", floor_values)
        ceil_values = test.ceil(arr)
        print("\nCeil values : \n", ceil_values)
        trunc_values = test.trunc(arr)
        print("\nTruncated values : \n", trunc_values)     
    
    # elif choice == 12:  
        
            
    elif choice == 13:  
        arr = get_array() 
        print("array : ", arr) 
        print("variance of array : ", test.var(arr)) 

    elif choice == 14:
        arr = get_array()
        print("array : ", arr) 
        print("standard deviation of array : ", test.std(arr))

    # elif choice == 15:
         
        
    # elif choice == 16:
         

    elif choice == 17:
       from numpy.polynomial import polynomial as P
       x = (10,20,30)
       y = (30,40,50)
       print("Add one polynomial to another:")
       print(P.polyadd(x,y))
       print("Subtract one polynomial from another:")
       print(P.polysub(x,y))
       print("Multiply one polynomial by another:")
       print(P.polymul(x,y))
       print("Divide one polynomial by another:")
       print(P.polydiv(x,y))      
   
    # elif choice == 18:  
        
            
    # elif choice == 19:  
           

    elif choice == 20:
        print("Enter the x coordinates - ")
        x=get_array
        print("Enter the y coordinates - ")
        y=get_array
        plt.title("Line graph")
        plt.xlabel("X axis")
        plt.ylabel("Y axis")
        plt.plot(x, y, color ="green")
        plt.show()

    elif choice == 22:  
            break  
              
    else:  
            print("Oops! Incorrect Choice.")  
     
