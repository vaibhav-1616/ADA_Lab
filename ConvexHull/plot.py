import pandas as pd
import matplotlib.pyplot as plt

# Load the data from the CSV files
try:
    all_points = pd.read_csv("all_points_data.csv")
    convex_hull = pd.read_csv("convex_hull_data.csv")
except FileNotFoundError:
    print("Error: CSV files not found. Make sure to run the C++ code first.")
    exit()

# Separate input points and convex hull points
input_points = all_points[["x", "y"]]
output_points = convex_hull[convex_hull["hull"] == True][["x", "y"]]  # Filter for hull points

# Create the scatter plot
plt.figure(figsize=(10, 6))  # Adjust figure size as needed
plt.scatter(input_points["x"], input_points["y"], label="input", color="blue")
plt.scatter(output_points["x"], output_points["y"], label="output", color="red")

# Add labels and title
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Convex Hull Visualization")

# Customize the plot (optional)
plt.grid(True)  # Add a grid
plt.xlim(-5, 105)  # Set x-axis limits (buffer for better visualization)
plt.ylim(-5, 105)  # Set y-axis limits

# Add legend
plt.legend()

# Show the plot
plt.show()

