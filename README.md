# 🎨 Computer Graphics in C++

Learning computer graphics from the ground up with **C++** and **OpenGL/GLUT**. From basic 2D shapes to 3D transformations.

## 🖼️ [See Rendered Examples](https://asimawad.github.io/projects/computer-graphics.html)

### 3D Cube
![3D Cube](https://asimawad.github.io/assets/graphics/cube.png)

### Mathematical Curves
![Mathematical Curves](https://asimawad.github.io/assets/graphics/curves.png)

### Regular Polygons
![Polygons](https://asimawad.github.io/assets/graphics/polygons.png)

### Data Visualization (Pie Chart)
![Pie Chart](https://asimawad.github.io/assets/graphics/piechart.png)

---

## 📁 Project Structure

```
├── Simple shapes and lines/    # Basic 2D primitives
├── Advanced Geometrics/        # Complex polygons, filled shapes
├── Curves/                     # Mathematical curves (polar coordinates)
└── Three Dimentional Drawing/  # 3D rendering with depth buffer
```

---

## 🧊 3D Graphics

### Colored Cube
Demonstrates:
- Perspective projection with `gluPerspective`
- Depth buffering (`GL_DEPTH_TEST`)
- Per-face vertex coloring
- 3D transformations (translate, rotate)

```cpp
glTranslatef(0.0, 0.0, -5.0);
glRotatef(30, 1.f, 1.f, 0.f);

glBegin(GL_QUADS);
  glColor3f(0.0f, 1.0f, 0.0f); // Green
  glVertex3f(-0.5f, -0.5f, 0.5f);
  glVertex3f( 0.5f, -0.5f, 0.5f);
  // ...
glEnd();
```

---

## 📐 Mathematical Curves

Curves rendered using polar coordinate equations:

| Curve | Equation |
|-------|----------|
| **Limacon** | r = a·cos(θ) + b |
| **Cardioid** | r = a·(1 + cos(θ)) |
| **Three-Leaf** | r = a·cos(3θ) |
| **Four-Leaf** | r = a·cos(2θ) |
| **Spiral** | r = a·θ |

---

## 🛠️ Building

```bash
# Install dependencies (Ubuntu/Debian)
sudo apt install freeglut3-dev libgl1-mesa-dev

# Compile a program
g++ -o cube "Three Dimentional Drawing/shape2-Cube.cpp" -lGL -lGLU -lglut

# Run
./cube
```

---

## 📚 Topics Covered

- **2D Graphics**: Lines, polygons, transformations
- **3D Graphics**: Cubes, perspective, depth buffering  
- **Curves**: Bezier, polar coordinate equations
- **Animation**: Timer callbacks, double buffering
- **Math**: Matrix transformations, trigonometry

---

## Author

**Asim Osman** — [Portfolio](https://asimawad.github.io) | [GitHub](https://github.com/Asimawad)
