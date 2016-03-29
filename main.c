#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h" 
#include "draw.h"
#include "matrix.h" 
#include "parser.h"

int main( int argc, char** argv ) {

  screen s;
  struct matrix *edges;
  struct matrix *transform;
  color c;
  c.red = 200;
  c.blue = 150;
  c.green = 150;
  
  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);

  clear_screen( s );
  
  add_sphere( edges, 250, 250, 50, .01 );
  add_torus( edges, 200, 200, 25, 50, .01 );
  add_box( edges, 250, 250, 0, 100, 100, 100 );
  
  draw_lines( edges, s, c );


  
  if ( argc == 2 )
    parse_file( argv[1], transform, edges, s );
  else
    parse_file( "stdin", transform, edges, s );

  display(s);
  
  free_matrix( transform );
  free_matrix( edges );
}  
