#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
	GLuint tex;
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque

	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

	// Draw a Red 1x1 Square centered at origin
	for (float i = -0.4; i < 0.9; i = i + 0.01)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
		glColor3f(1.0f, 0.0f, 0.0f); // Red
		glVertex2f(i + -0.5f, -0.5f);    // x, y
		glVertex2f(i + 0.5f, -0.5f);
		glVertex2f(i + 0.5f, 0.5f);
		glVertex2f(i + -0.5f, 0.5f);
		glEnd();

		glFlush();  // Render now



		// Draw a Red 1x1 Square centered at origin
		glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
		glColor3f(9.0f, 9.0f, .0f); // Red
		glVertex2f(-0.5f, -0.5f + i);    // x, y
		glVertex2f(0.5f, -0.5f + i);
		glVertex2f(0.5f, 0.5f + i);
		glVertex2f(-0.5f, 0.5f + i);
		glEnd();

		glFlush();  // Render now
		Sleep(100);

	}

}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("CG HW1 Maryam"); // Create a window with the given title
	glutInitWindowSize(600, 600);   // Set the window's initial width & height
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}