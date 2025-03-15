import pandas as pd
import matplotlib.pyplot as plt

# Read CSV file
df = pd.read_csv("convex_hull.csv")

# Separate points and hull points
points = df[df['type'] == 'point']
hull = df[df['type'] == 'hull']

# Scatter plot for all points
plt.scatter(points['x'], points['y'], label="Points", color="blue")

# Plot convex hull points and connect them
# hull = hull.append(hull.iloc[0])  # To close the convex hull shape
plt.plot(hull['x'], hull['y'], label="Convex Hull", color="red", linestyle="none", marker="o")

plt.xlabel("X")
plt.ylabel("Y")
plt.legend()
plt.title("Convex Hull using QuickHull")
plt.show()
