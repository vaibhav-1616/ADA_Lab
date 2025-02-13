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
                  decreases the time complexity (near O(n log n)... 
              </li>
          </ul>
      </li>
    </ol>
