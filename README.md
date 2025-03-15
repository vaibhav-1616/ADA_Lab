<h1> Analysis and Design of Algorithms </h1>
<!-- <hr> -->
    <h3>List of all my ADA programs:</h3>
<!-- <hr> -->
    <ol>
      <li><b>QuickSort Algorithm:</b> <br>
          <ul>
              <li>This is an efficient sorting algorithm that wroks well for larger input values.
              </li>
              <li>In this algorithm, we select a pivot element and then partition the entire array 
                  around that pivot <br> to ensure that elements greater than the pivot are to the right of it and smaller elements are to the left of it. </li><br>
                  <img src="./Graphs/quicksort.png" width="700px"/> <br>
              <li>
                  Inherently, a recursion stack is used to perform sorting of the elements according to the pivot element. <br>
                  But, that results in a larger time complexity of the O(n^2) which is highly undesirable... <br>
                  Instead, we prefer to the use the iterative quicksort using a user-defined stack that significantly <br>
                  decreases the time complexity (near O(n log n))... 
                  <br>
                  <img src="./Graphs/quicksort_iterative.png" width="700px"/> <br>
              </li>
          </ul>
      </li> <br>
      <li>
          <b>Peak finding:</b> <br>
          <ul>
              <li>
                  In 1D array, it is simple to find the peak element by just following the approach <br>
                  of comparing each element with its immediate left and right elements and if it is greater than both of them, <br>
                  that is the Peak :D
              </li>
              <li>
                  In a 2D array, we implement the same approach but with a binary search twist.
              </li>
          </ul>
      </li> <br>
      <li>
          <b>Magic Square</b> <br>
          <ul>
              <li>(Odd Size)Sum of all rows, columns and diagonals is equal... Creates a square matrix where the sum of all colums,<br> rows and diagonals is equal
Follows a set pattern in where the numbers increase in a diagonal upwards to the left<br> and goes down one when number is a multiple of the size...</li>
          </ul>
      </li><br>  
        <li>
          <b>Fractional Knapsack</b> <br>
          <ul>
              <li>Problem involving the calculation of maximum profit that can be derived from a given set of values</li>
              <li>We sort the array according to the criterion we need(here we sort 3 time, according to profit, weight and <br>ratio of profit/weight) and then pick the items in non-increasing manner</li>
              <li>In this problem, we can include fractional parts of an item as well incase an item cannot be included<br> completely in the knapsack...
              <br>
                  <img src="./Graphs/knapsack.png" width="700px"/> <br>
              </li>
          </ul>
      </li><br> 
        <li>
          <b>Activity Selection</b> <br>
          <ul>
              <li>We want to ensure that maximum number of jobs(or activities) are scheduled/completed within a given period of time...</li>
              <li>The goal is to maximize the number of jobs(or CPU usage) by ensuring highest amount of jobs that can be completed without<br> any overlap.</li>
              <li>In this problem, sort the activities by their start time and then by their finish times to calculate which method leads to max<br> number of activities that get completed without any overlap.
              <br>
                  <img src="./Graphs/activity_selection.png" width="700px"/> <br>
              </li>
          </ul>
      </li><br> 
    </ol>
