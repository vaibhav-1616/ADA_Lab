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
                  <img src="./Graphs/quicksort.png"/> <br>
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
          <b></b>
      </li>  
    </ol>
