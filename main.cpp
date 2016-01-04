#include "world.h"
#include "room.h"
#include "game.h"
#define red makecol(255, 0, 0)
#define light_gray makecol(150,150,150)
void init();
void deinit();
int loadingBarX = 100;
int loadingBarHeight = 200;
int loadingBarY = 100;
int loadingBarWidth = 30;

//One of these rules state that the variables handled in your ticker need be volatile
   //So let's declare it globally.
   volatile int ticks=0;
 
   //Then comes the ticker, in my example it simply increments ticks.
   //After the function another rule bothers us.
   //You need the macro END_OF_FUNCTION after the ticker.
   void ticker()
   {
      ticks++;
   }
   END_OF_FUNCTION(ticker)
 
   //Time to install our timer.
   //Before doing that, we simply must follow the rules.
   //Lock variable and function using those nice macros.

//lets create a global bool to check if the window x is pressed
volatile bool close_button_pressed = false;



      void close_button_handler(void)
      {
	       close_button_pressed = true;
      }
      END_OF_FUNCTION(close_button_handler)


int main() {
	init();
	Game game;
	LOCK_VARIABLE(ticks);
    LOCK_FUNCTION(ticker);
 
      //Finally we can install the timer, using either method.
    install_int(ticker,10);
    install_int_ex(ticker, BPS_TO_TIMER(100));
    LOCK_FUNCTION(close_button_handler);
    set_close_button_callback(close_button_handler);

	/*
    //Room rm (1, 640, 480);
    textout_ex(screen, font, "Loading...", loadingBarX, loadingBarY-90, -1, 0);
    //rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth, loadingBarHeight, red);
    rect(screen, loadingBarX, loadingBarY, loadingBarWidth+400, loadingBarHeight, light_gray);
    Body b;
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+100, loadingBarHeight, red);
    rect(screen, loadingBarX, loadingBarY, loadingBarWidth+400, loadingBarHeight, light_gray);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+110, loadingBarHeight, red);
    BITMAP * screenBuffer = create_bitmap(5080, 2000);  
    //rm.addBody(b);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+100, loadingBarHeight, red);
    rect(screen, loadingBarX, loadingBarY, loadingBarWidth+400, loadingBarHeight, light_gray);
    World world(640, 480);
    rest(20);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+200, loadingBarHeight, red);
    rect(screen, loadingBarX, loadingBarY, loadingBarWidth+400, loadingBarHeight, light_gray);
    world.buildAllRooms();
    rest(20);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+300, loadingBarHeight, red);
    rect(screen, loadingBarX, loadingBarY, loadingBarWidth+400, loadingBarHeight, light_gray);
    world.loadRoom(0);
    
    world.update(screenBuffer);
    rest(20);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+310, loadingBarHeight, red);
    world.update(screenBuffer);
    rest(20);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+320, loadingBarHeight, red);
    world.update(screenBuffer);
    rest(20);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+340, loadingBarHeight, red);
    world.drawAll(screenBuffer);
    rest(20);
    world.update(screenBuffer);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+350, loadingBarHeight, red);
    rest(20);
    world.drawAll(screenBuffer);
    world.update(screenBuffer);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+360, loadingBarHeight, red);
    world.drawAll(screenBuffer);
    rest(20);
    world.update(screenBuffer);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+370, loadingBarHeight, red);
    world.drawAll(screenBuffer);
    world.update(screenBuffer);
    rest(20);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+380, loadingBarHeight, red);
    world.drawAll(screenBuffer);
    world.update(screenBuffer);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+390, loadingBarHeight, red);
    world.drawAll(screenBuffer);
    world.update(screenBuffer);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+390, loadingBarHeight, red);
    world.drawAll(screenBuffer);
    world.update(screenBuffer);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+395, loadingBarHeight, red);
    world.drawAll(screenBuffer);
    world.update(screenBuffer);
    // Load and play the sound.
    SAMPLE *backgroundMusic ; 
    backgroundMusic = load_sample("background.wav"); // or .voc
    if (backgroundMusic !=0)
       int sound = play_sample(backgroundMusic, 128, 128, 1000, 1);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+400, loadingBarHeight, red);
    rect(screen, loadingBarX, loadingBarY, loadingBarWidth+400, loadingBarHeight, light_gray);
    textout_ex(screen, font, "Press Enter to start :)", loadingBarX, loadingBarY+loadingBarHeight+90, -1, 0);
    */
    int deltaTime = 0;
    int oldTime = 0;
    oldTime = ticks;
    game.load();
    //rest(1111);
    deltaTime = ticks - oldTime ;
    textprintf_ex(screen, font, 100, 450, makecol(255, 100, 200), -1, "Done loading in %d", deltaTime/100);
    textprintf_ex(screen, font, 235, 450, makecol(255, 100, 200), -1, ".%d seconds", deltaTime%100);
    //textprintf_ex(screen, font, 250, 450, makecol(255, 100, 200), -1, "Seconds", deltaTime%10);
    while (!key[KEY_ENTER] && !key[KEY_ESC])
    {
	 	  //
    }
    BITMAP * screenBuffer = create_bitmap(5080, 720);
    
    clear(screen);
	while (!key[KEY_ESC] && !close_button_pressed) {
 		  oldTime = ticks;
		/* put your code here */
		game.update(screenBuffer, deltaTime);
		//clear(screenBuffer);
		blit (screenBuffer, screen, game.getCamX(), game.getCamY(), 0,  0, screen->w, screen->h);
		//masked_blit(screenBuffer, screen, world.getCameraX(), world.getCameraY(), 0, 0, screen->w, screen->h);
        deltaTime = ticks - oldTime ;
        
		clear(screenBuffer);
      	deltaTime = ticks - oldTime ;
	    
	}
    game.saveToFile();
	deinit();
	return 0;
	
}
END_OF_MAIN()

void init() {
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0); //change to fullscreen
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}
     if (install_sound(DIGI_AUTODETECT, MIDI_NONE, NULL) != 0) {
      set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
      allegro_message("Error initialising sound driver\n%s\n",
		      allegro_error);
   }

   /* we want a _real_ sound driver */
   if (digi_card == DIGI_NONE) {
      set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
      allegro_message("Unable to find a sound driver\n%s\n",
		      allegro_error);
   }
	install_timer();
	install_keyboard();
	install_mouse();
	/* add other initializations here */
}

void deinit() {
	clear_keybuf();
	remove_sound();
	allegro_exit();
	exit(-1);
	/* add other deinitializations here */
}
