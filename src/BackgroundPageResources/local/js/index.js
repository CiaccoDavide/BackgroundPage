
var NUM_PARTICLES = ( ( ROWS = 100 ) * ( COLS = 100 ) ),
    THICKNESS = Math.pow( 80, 2 ),
    SPACING = 6,
    MARGIN = 100,
    COLOR = 120,
    DRAG = 0.95,
    EASE = 0.25,
    B = 4 / Math.PI,
    C = -4 / Math.pow( Math.PI, 2 ),
    P = 0.225,
    container,
    particle,
    canvas,
    mouse,
    list,
    ctx,
    tog,
    dx, dy,
    mx, my,
    d, t, f,
    a, b,
    i, n,
    w, h,
    p, s,
    r, c
    ;

particle = {
  vx: 0,
  vy: 0,
  x: 0,
  y: 0
};

function init() {

  container = document.getElementById( 'container' );
  canvas = document.createElement( 'canvas' );
  
  ctx = canvas.getContext( '2d' );
  tog = true;
  
  list = [];
  
  w = canvas.width = COLS * SPACING + MARGIN * 2;
  h = canvas.height = ROWS * SPACING + MARGIN * 2;
  
  container.style.marginLeft = Math.round( w * -0.5 ) + 'px';
  container.style.marginTop = Math.round( h * -0.5 ) + 'px';
  
  for ( i = 0; i < NUM_PARTICLES; i++ ) {
    
    p = Object.create( particle );
    p.x = p.ox = MARGIN + SPACING * ( i % COLS );
    p.y = p.oy = MARGIN + SPACING * Math.floor( i / COLS );
    
    list[i] = p;
  }

  container.addEventListener( 'mousemove', function(e) {
    bounds = container.getBoundingClientRect();
    mx = e.clientX - bounds.left;
    my = e.clientY - bounds.top;
  });
  
  container.appendChild( canvas );
}

function step() {
  if ( tog = !tog ) {
    for ( i = 0; i < NUM_PARTICLES; i++ ) {
      p = list[i];
      d = ( dx = mx - p.x ) * dx + ( dy = my - p.y ) * dy;
      f = -THICKNESS / d;

      if ( d < THICKNESS ) {
        t = Math.atan2( dy, dx );
        p.vx += f * Math.cos(t);
        p.vy += f * sine3(t);
      }

      p.x += ( p.vx *= DRAG ) + (p.ox - p.x) * EASE;
      p.y += ( p.vy *= DRAG ) + (p.oy - p.y) * EASE;

    }

  } else {

    b = ( a = ctx.createImageData( w, h ) ).data;

    for ( i = 0; i < NUM_PARTICLES; i++ ) {

      p = list[i];
COLOR=Math.floor((Math.random() * 150)+100); 
      b[n = ( ~~p.x + ( ~~p.y * w ) ) * 4] = b[n+1] = b[n+2] = COLOR, b[n+3] = 255;
    }
    ctx.putImageData( a, 0, 0 );
  }
  requestAnimationFrame( step );
}
 function sine3( x ) {
    if(x<0)
      return x*(B + C * x);
    return x*(B-C*x)
  }
init();
step();
