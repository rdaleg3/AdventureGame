//TODO: Add Use menu to combat
//DONE =) : Make adding new hats a little less hellish
//TODO: Make 3 new rooms
//TODO: Can we get it so room triggers are easy enough to make?
//TODO: Cutscenes :P
//TODO: FIX THE World::drawHat(BITMAP* drawHere) fuction
//TODO: Make a more efficent "drawPlayer(BITMAP* PL)"

#include "game.h"
#define red makecol(255, 0, 0)
#define light_gray makecol(150,150,150)
#define gold makecol(200, 210, 0)
using namespace std;
Game::Game()
{
    displayText = "";
    playerName = "Dale";
    message = "";
    frames = 0;
    messageTimer = 0;
    gameState = 1;
    for (int i = 0; i < 32; i++)
    {
        keyPresses[i] = true;
    }
    for (int i = 0; i < 50; i++)
    {
        hasBeenTriggered[i] = false;
    }
    for (int i = 0; i < 50; i++)
    {
        interactedWith[i] = false;
    }
    
}
int Game::textout_hack( BITMAP *b , FONT *font , int x , int y , double multiplier , const char *msg , int color )
{
   //init();
   BITMAP *tmp;
   
   tmp = create_bitmap( text_length(font, msg), text_height(font));
   
   if( !tmp){
      //deinit();
      return FALSE;
   }
   clear_to_color( tmp , makecol( 255 , 0 , 255 ) );
   textout_ex( tmp, font, msg, 0, 0, color, -1) ;
   
   masked_stretch_blit( tmp , b , 0 , 0 , tmp -> w , tmp -> h , x , y , (int)(tmp -> w * multiplier), (int)(tmp -> h * multiplier)); 
   
   destroy_bitmap( tmp );
   //deinit();
   return TRUE;
   
}
int Game::textout_hack( BITMAP *b , FONT *font , int x , int y , double multiplier , const char *msg , int color , int bkgColor)
{
   //init();
   BITMAP *tmp;
   
   tmp = create_bitmap( text_length(font, msg), text_height(font));
   
   if( !tmp){
      //deinit();
      return FALSE;
   }
   clear_to_color( tmp , bkgColor );
   textout_ex( tmp, font, msg, 0, 0, color, bkgColor) ;
   
   masked_stretch_blit( tmp , b , 0 , 0 , tmp -> w , tmp -> h , x , y , (int)(tmp -> w * multiplier), (int)(tmp -> h * multiplier)); 
   
   destroy_bitmap( tmp );
   //deinit();
   return TRUE;
   
}
void Game::update(BITMAP *sb, int dt)
{
     //world.update(dt);
      
       if (gameState == 0)
       {
          world.update(dt);
          world.drawAll(sb);
          roomNumber = world.getRoom();
       }
       
       else if (gameState == 1)
       {
            
            combat(sb, enemyAtID, dt);
       }
       else if (gameState == 2)
       {
            world.drawAll(sb);
            drawInventory(sb);
       }
	   
	   if (playerHP <= 0)
	   {
 			gameState = 0;
 			stop_sample(backgroundMusic);
    		gameOverMusic = load_sample("gameOver.wav"); // or .voc
    		if (gameOverMusic !=0)
       		int sound = play_sample(gameOverMusic, 500, 500, 1000, 1);
 			
 			string gameOver = "Don't give up now " + playerName + " the people need you!";
 			string temp1 = "Don't give up now ";
             while (gameOver.substr(34, 1).compare(" ") != 0)
 			{
               temp1 += " ";
               gameOver = temp1 + playerName + " the people need you!";
            }
	   	  	setMessage(gameOver);
	   	  	stop_sample(gameOverMusic);
	   	  	play_sample(backgroundMusic, 500, 500, 1000, 1);
	   	  	reload();
       }
       triggers (sb,  dt);  
      //rest(25);
     //textprintf_ex(screen, font, 50, 60, makecol(255, 100, 200), -1, "DebugA: %d", quickTest);
     int keyCode = 0; // this way I don't have to track the number of each key :)
     // "A" Key pressed...
     if (key[KEY_A])
     {
        if (!keyPresses[keyCode])
        {
           keyPresses[keyCode] = true;                      
           onKeyPress("a", sb);
        }
     }
     else{
         keyPresses[keyCode] = false;
     }
     keyCode++;
     // "B" Key pressed...
     if (key[KEY_B])
     {
        if (!keyPresses[keyCode])
        {
           keyPresses[keyCode] = true;
           onKeyPress("b", sb);
        }
     }
     else{
         keyPresses[keyCode] = false;
     }
     keyCode++;
     // "LEFT" Key pressed...
     if (key[KEY_LEFT])
     {
        if (!keyPresses[keyCode])
        {
           keyPresses[keyCode] = true;
           onKeyPress("left", sb);
        }
     }
     else{
         keyPresses[keyCode] = false;
     }
     keyCode++;
     // "RIGHT" Key pressed...
     if (key[KEY_RIGHT])
     {
        if (!keyPresses[keyCode])
        {
           keyPresses[keyCode] = true;                                 
           onKeyPress("right", sb);
        }
     }
     else{
         keyPresses[keyCode] = false;
     }
     keyCode++;
     // "UP" Key pressed...
     if (key[KEY_UP])
     {
        if (!keyPresses[keyCode])
        {
           keyPresses[keyCode] = true;                                 
           onKeyPress("up", sb);
        }
     }
     else{
         keyPresses[keyCode] = false;
     }
     keyCode++;
     // "down" Key pressed...
     if (key[KEY_DOWN])
     {
        if (!keyPresses[keyCode])
        {
           keyPresses[keyCode] = true;                                 
           onKeyPress("down", sb);
        }
     }
     else{
         keyPresses[keyCode] = false;
     }
     keyCode++;
     // "Enter" Key pressed...
     if (key[KEY_ENTER] || key[KEY_Z])
     {
        if (!keyPresses[keyCode])
        {
           keyPresses[keyCode] = true;                                 
           onKeyPress("enter", sb);
        }
     }
     else{
         keyPresses[keyCode] = false;
     }
     keyCode++;
      // "SpaceBar" Key pressed...
     if (key[KEY_SPACE])
     {
        if (!keyPresses[keyCode])
        {
           keyPresses[keyCode] = true;                                 
           onKeyPress(" ", sb);
        }
     }
     else{
         keyPresses[keyCode] = false;
     }
     keyCode++;
     /////////////////////////////////////////////////////////////////////////////////
     // "C" Key pressed...
     if (key[KEY_C])
     {
        if (!keyPresses[keyCode])
        {
           keyPresses[keyCode] = true;                      
           onKeyPress("c", sb);
        }
     }
     else{
         keyPresses[keyCode] = false;
     }
     keyCode++;
     // "D" Key pressed...
     if (key[KEY_D])
     {
        if (!keyPresses[keyCode])
        {
           keyPresses[keyCode] = true;
           onKeyPress("d", sb);
        }
     }
     else{
         keyPresses[keyCode] = false;
     }
     keyCode++;
     // "E" Key pressed...
     if (key[KEY_E])
     {
        if (!keyPresses[keyCode])
        {
           keyPresses[keyCode] = true;
           onKeyPress("e", sb);
        }
     }
     else{
         keyPresses[keyCode] = false;
     }
     keyCode++;
     // "F" Key pressed...
     if (key[KEY_F])
     {
        if (!keyPresses[keyCode])
        {
           keyPresses[keyCode] = true;                                 
           onKeyPress("f", sb);
        }
     }
     else{
         keyPresses[keyCode] = false;
     }
     keyCode++;
     // "G" Key pressed...
     if (key[KEY_G])
     {
        if (!keyPresses[keyCode])
        {
           keyPresses[keyCode] = true;                                 
           onKeyPress("g", sb);
        }
     }
     else{
         keyPresses[keyCode] = false;
     }
     keyCode++;
     // "H" Key pressed...
     if (key[KEY_H])
     {
        if (!keyPresses[keyCode])
        {
           keyPresses[keyCode] = true;                                 
           onKeyPress("h", sb);
        }
     }
     else{
         keyPresses[keyCode] = false;
     }
     keyCode++;
      // "I" Key pressed...
     if (key[KEY_I])
     {
        if (!keyPresses[keyCode])
        {
           keyPresses[keyCode] = true;                                 
           onKeyPress("i", sb);
        }
     }
     else{
         keyPresses[keyCode] = false;
     }
     keyCode++;
     // "Left Control" Key pressed...
     if (key[KEY_LCONTROL])
     {
        if (!keyPresses[keyCode])
        {
           keyPresses[keyCode] = true;                                 
           onKeyPress("ctrl", sb);
        }
     }
     else{
         keyPresses[keyCode] = false;
     }
     keyCode++;
     if (key[KEY_RCONTROL])
     {
        if (!keyPresses[keyCode])
        {
           keyPresses[keyCode] = true;                                 
           onKeyPress("ctrl", sb);
        }
     }
     else{
         keyPresses[keyCode] = false;
     }
     keyCode++;
     if (key[KEY_X])
     {
        if (!keyPresses[keyCode])
        {
           keyPresses[keyCode] = true;                                 
           onKeyPress("ctrl", sb);
        }
     }
     else{
         keyPresses[keyCode] = false;
     }
     keyCode++;
     // "Z" Key pressed...
     if (key[KEY_Z])
     {
        if (!keyPresses[keyCode])
        {
           keyPresses[keyCode] = true;                                 
           onKeyPress("z", sb);
        }
     }
     else{
         keyPresses[keyCode] = false;
     }
     keyCode++;
}

int Game::getCamX()
{
    return world.getCameraX();
}
int Game::getCamY()
{
    return world.getCameraY();
}
void Game::load()
{
     
    int loadingBarX = 100;
    int loadingBarHeight = 200;
    int loadingBarY = 100;
    int loadingBarWidth = 30;
    textout_ex(screen, font, "LOADING...", loadingBarX, loadingBarY-90, -1, 0);
    textout_ex(screen, font, "Press Esc to quit, Enter/Z to interact, and have fun!", loadingBarX, loadingBarY-30, -1, 0);
    BITMAP* temp = create_bitmap(5080, 720);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+200, loadingBarHeight, red);
    rect(screen, loadingBarX, loadingBarY, loadingBarWidth+400, loadingBarHeight, light_gray);
    world.buildAllRooms();
    loading = load_bitmap("player_walk_0_0.bmp", NULL);
    rest(20);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+300, loadingBarHeight, red);
    rect(screen, loadingBarX, loadingBarY, loadingBarWidth+400, loadingBarHeight, light_gray);
	textout_ex(screen, font, "Building rooms", loadingBarX, loadingBarY+130, -1, 0);
    loadFromFile();
    textout_ex(screen, font, "Loading save", loadingBarX, loadingBarY+140, -1, 0);
    world.loadRoom(roomNumber);
    textout_ex(screen, font, "Loading room", loadingBarX, loadingBarY+150, -1, 0);    
    //
    //world.update();
    //rest(20);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+310, loadingBarHeight, red);
    world.update(0);
    textout_ex(screen, font, "Preparing world", loadingBarX, loadingBarY+160, -1, 0);
    //rest(20);
    
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+320, loadingBarHeight, red);
    world.update(0);
    
    //rest(20);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+340, loadingBarHeight, red);
    //world.drawAll(temp);
    //textout_ex(screen, font, "World half-pepared", loadingBarX, loadingBarY+170, -1, 0);
    
    //rest(20);
    world.update(0);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+350, loadingBarHeight, red);
    //rest(20);
    world.drawAll(temp);
    world.update(0);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+360, loadingBarHeight, red);
    world.drawAll(temp);
    //rest(20);
    world.update(0);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+370, loadingBarHeight, red);
    world.drawAll(temp);
    world.update(0);
    //rest(20);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+380, loadingBarHeight, red);
    world.drawAll(temp);
    world.update(0);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+390, loadingBarHeight, red);
    world.drawAll(temp);
    world.update(0);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+390, loadingBarHeight, red);
    world.drawAll(temp);
    world.update(0);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+390, loadingBarHeight, red);
    world.drawAll(temp);
    world.update(0);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+390, loadingBarHeight, red);
    world.drawAll(temp);
    world.update(0);

    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+390, loadingBarHeight, red);
    world.drawAll(temp);
    world.update(0);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+390, loadingBarHeight, red);
    world.drawAll(temp);
    world.update(0);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+390, loadingBarHeight, red);
    world.drawAll(temp);
    world.update(0);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+390, loadingBarHeight, red);
    world.drawAll(temp);
    world.update(0);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+390, loadingBarHeight, red);
    world.drawAll(temp);
    world.update(0);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+390, loadingBarHeight, red);
    world.drawAll(temp);
    world.update(0);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+390, loadingBarHeight, red);
    world.drawAll(temp);
    world.update(0);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+390, loadingBarHeight, red);
    world.drawAll(temp);
    world.update(0);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+390, loadingBarHeight, red);
    world.drawAll(temp);
    world.update(0);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+390, loadingBarHeight, red);
    world.drawAll(temp);
    world.update(0);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+390, loadingBarHeight, red);
    world.drawAll(temp);
    world.update(0);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+390, loadingBarHeight, red);
    world.drawAll(temp);
    world.update(0);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+390, loadingBarHeight, red);
    world.drawAll(temp);
    world.update(0);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+390, loadingBarHeight, red);
    world.drawAll(temp);
    world.update(0);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+390, loadingBarHeight, red);
    world.drawAll(temp);
    world.update(0);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+390, loadingBarHeight, red);
    world.drawAll(temp);
    world.update(0);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+395, loadingBarHeight, red);
    world.drawAll(temp);
    world.update(0);
    textout_ex(screen, font, "World pepared", loadingBarX, loadingBarY+170, -1, 0);
    buildEnemies();
    textout_ex(screen, font, "Enemies pepared", loadingBarX, loadingBarY+180, -1, 0);
    startCombat(1);
    textout_ex(screen, font, "Combat pepared", loadingBarX, loadingBarY+190, -1, 0);
    playerHP = 20;
    playerHPCap = 20;
    // Load and play the sound.
     textout_ex(screen, font, "Loading sound", loadingBarX, loadingBarY+200, -1, 0);
    backgroundMusic = load_sample("background.wav"); // or .voc
    if (backgroundMusic !=0)
       int sound = play_sample(backgroundMusic, 500, 500, 1000, 1);
    rectfill(screen, loadingBarX, loadingBarY, loadingBarWidth+400, loadingBarHeight, red);
    rect(screen, loadingBarX, loadingBarY, loadingBarWidth+400, loadingBarHeight, light_gray);
    textout_ex(screen, font, "Press Enter to start :)", loadingBarX, loadingBarY+loadingBarHeight+90, -1, 0);
    
    
    //return true;
}
void Game::reload()
{
     playerHP = playerHPCap;
     loadFromFile();
}
void Game::startCombat (int enemyID)
{
     gameState = 1;
     cursorX = 0;
     cursorY = 0;
     cursorXLimit = 1;//enemyLibrary[enemyID].getNumberOfActions()/3;
     //if (enemyLibrary[enemyID].getNumberOfActions() >= 3)
     //{
     cursorYLimit = (enemyLibrary[enemyID].getNumberOfActions()/2);
     enemyAtID = enemyID;
     if (cursorYLimit >= 1)
        cursorYLimit--;
         //cursorYLimit1 = 1;
     //}
     combatStep = 0;
     world.setCameraX(0);
	 world.setCameraY(0);
}
void Game::buildEnemies ()
{
     Enemy cat("cat", 1, 1, "pet", 1, 1, "I think he likes it", -5, 1, 2, "null.bmp", 5);// id 0
     
     enemyLibrary.push_back(cat);
     Enemy wildHog ("Hog", 5, 5, "Threaten", 1, -1, "He seems angry", "Cook", 1, -5, "You prepare a plate of bacon... I think it's angry.", "Pet", 1, 0, "This isn't a cat", "Kiss", 1, 5, "Wet and gross... it seems pleased", -10, 5, 8, "null.bmp", 12);
     enemyLibrary.push_back(wildHog);
}
void Game::combat(BITMAP *sb, int enemyID, int dt)
{    
     
     
     textout_ex(sb, font, enemyLibrary[enemyID].getName().c_str(), getCamX()+200 , getCamY()+90, -1, 0);
     if (combatStep == 0)
     {       
            rectfill (sb, (cursorX*150)+50, 400, (cursorX*150)+100, 460, gold );
            textout_ex(sb, font, "Attack", 50, 420, -1, 0);
            textout_ex(sb, font, "Act", 150+50, 420, -1, 0);
            textout_ex(sb, font, "Use", 300+50, 420, -1, 0);
            textout_ex(sb, font, "Flee", 450+50, 420, -1, 0);
            if (cursorX == 0)
               textout_ex(sb, font, "Attack", 50, 420, -1, gold);
            else if (cursorX == 1)
                 textout_ex(sb, font, "Act", 150+50, 420, -1, gold);
            else if (cursorX == 2)
                 textout_ex(sb, font, "Use", 300+50, 420, -1, gold);
            else if (cursorX == 3)
                 textout_ex(sb, font, "Flee", 450+50, 420, -1, gold);
     }
     
     else if (combatStep == 1)
     {
          rectfill (sb, (cursorX*250)+50, (cursorY*100)+150, (cursorX*250)+300, (cursorY*100)+250, gold );          
          for (int i = 0; i < 2; i++)
         {
             for (int j = 0; j < 3; j++)
             {
                 string checkFirst = enemyLibrary[enemyID].getOption(i, j);
                 if (checkFirst.compare("OP_NULL") != 0)
                    textout_ex(sb, font, checkFirst.c_str(), (i*250)+100 , (j*100)+200, -1, 0);
             }
         }
        
     }    
     else if (combatStep == 2)
     { 
        enemyLibrary[enemyID].takeDamage(playerAttack);
        combatStep = -5;
     }
     else if (combatStep == 3)
     {
          
     }   
     else if (combatStep == 4)
     {
          gameState = 0;
     }
     else if (combatStep == -5)
     {
          flappyTimer = 0;
          combatStep = -1;
          invTimer = 0;
          birdY = 300;
          birdYVelocity = 0;
          pipe1X = 100;
          pipe1Y = rand()%230+210;
          
          pipe2X = 300;
          pipe2Y = rand()%230+210;
          
          pipe3X = 500;
          pipe3Y = rand()%230+210;
          
          
          frames = 0;
     }
     if (combatStep == -1)    
     {
                    flappyGame(enemyID, sb, dt);
     }
     textprintf_ex(sb, font, getCamX()+200, getCamY()+200, makecol(255, 100, 200), -1, "KP: %d", enemyLibrary[enemyID].getKarma());
     textprintf_ex(sb, font, getCamX()+200, getCamY()+300, makecol(255, 100, 200), -1, "TEST: %d", combatStep);
     textprintf_ex(sb, font, getCamX()+200, getCamY()+350, makecol(255, 100, 200), -1, "HP: %d", playerHP);
     textprintf_ex(sb, font, getCamX()+200, getCamY()+400, makecol(255, 100, 200), -1, "X: %d", cursorX);
     textprintf_ex(sb, font, getCamX()+200, getCamY()+450, makecol(255, 100, 200), -1, "Y: %d", (int)birdY);
     
     
      switch (frames/5)
   			    {
                       case 0:
                            loading = load_bitmap("player_walk_0_0.bmp", NULL);
                            break;
                       case 1:
                            loading = load_bitmap("player_walk_0_0.bmp", NULL);
                            break;
                       case 2:
                            loading = load_bitmap("player_walk_0_1.bmp", NULL);
                            break;
                       case 3:
                            loading = load_bitmap("player_walk_0_1.bmp", NULL);
                            break;
                       case 4:
                            loading = load_bitmap("player_walk_0_2.bmp", NULL);
                            break;
                       case 5:
                            loading = load_bitmap("player_walk_0_2.bmp", NULL);
                            break;
                       case 6:
                            loading = load_bitmap("player_walk_0_3.bmp", NULL);
                            break;
                       case 7:
                            loading = load_bitmap("player_walk_0_3.bmp", NULL);
                            break;
                       case 8:
                            loading = load_bitmap("player_walk_0_2.bmp", NULL);
                            break;
                       case 9:
                            loading = load_bitmap("player_walk_0_2.bmp", NULL);
                            break;
                       case 10:
                            loading = load_bitmap("player_walk_0_1.bmp", NULL);
                            break;
                       case 11:
                            loading = load_bitmap("player_walk_0_1.bmp", NULL);
                            break;
                       
               }
               frames++;
               frames = frames%60; 
      masked_blit(loading, sb, 0, 0, 50, 50, loading->w, loading->h);
      
      if(enemyLibrary[enemyID].isComplete() || !enemyLibrary[enemyID].isAlive())
      {
          gameState = 0;
      }
} 

bool Game::onKeyPress(string keyCode,  BITMAP * screenForText)
{
     if (gameState == 0)
     {
         if (keyCode.compare("enter") == 0 || keyCode.compare("z") == 0)
         {
             //if the player is touching something it gets the User Data of the
             //body in question, stores it, then displays the response........
             string checkUserData = world.getColisionData();
             if (checkUserData.compare("block") == 0)
             {
                   setMessage("this is a test you scrub");
             }
             else if (checkUserData.compare("bed") == 0)
             {
                   setMessage("It's a comfy bed, but you are not tired...");
             }
             else if (checkUserData.compare("dirtyClothes") == 0)
             {
                   setMessage("These are the clothes that failed the sniff test.");
             }
             else if (checkUserData.compare("TV") == 0)
             {
                   setMessage("There is nothing on but reality TV");
             }
             else if (checkUserData.compare("fence") == 0)
             {
                   setMessage("Your garden is so pretty");
             }
             else if (checkUserData.compare("hallwayTable") == 0)
             {
                  if (interactedWith[0])
                  {
                    setMessage("The desk is empty");
                  }
                  else
                  {
                      if (setOption("You see a piece of candy inside   the desk", "Take it!", "Leave it!"))
                      {
    				   	 		 clear(screen);	
    							 blit (screenForText, screen, world.getCameraX(), world.getCameraY(), 0,  0, screen->w, screen->h);	 
    			 				 setMessage("You took the candy");
    			 				 interactedWith[0] = true;
    			 				 addToInventory(0);//adds candy to inventory
    				  }
    				  else
    				  {
    				   	  clear(screen);	
    					  blit (screenForText, screen, world.getCameraX(), world.getCameraY(), 0,  0, screen->w, screen->h);	
    				   	  setMessage("You left it there for later");
    				  }
               }
             }
             else if (checkUserData.compare("hatStand") == 0)
             {
                  if (interactedWith[1])
                  {
                    setMessage("You already took a hat");
                  }
                  else
                  {
                      if (setOption("You can either take the Propeller Hat or the Santa Hat", "Propeller Hat", "Santa Hat"))
                      {
    				   	 		 clear(screen);	
    							 blit (screenForText, screen, world.getCameraX(), world.getCameraY(), 0,  0, screen->w, screen->h);	 
    			 				 setMessage("You took the propeller hat");
    			 				 interactedWith[1] = true;
    			 				 addToInventory(1);//adds a hat to inventory
    				  }
    				  else
    				  {
    				   	  clear(screen);	
    					  blit (screenForText, screen, world.getCameraX(), world.getCameraY(), 0,  0, screen->w, screen->h);	 
    	 				  setMessage("You took the Santa hat");
    	 				  interactedWith[1] = true;
    	 				  addToInventory(2);
    				  }
                 }                  
             }
             return true;
         }
         else if (keyCode.compare("i") == 0 || keyCode.compare("ctrl") == 0)
        {
              cursorX = 0;
              cursorY = 0;
              itemSelected = false;
              gameState = 2;
        }
     }
     else if (gameState == 1)
     {
                   
        if (keyCode.compare("right") == 0)
        {
             cursorX++;
             if (cursorX > cursorXLimit && combatStep == 1)
             {
                 cursorX = cursorXLimit;
             }
             else if (cursorX > 3 && combatStep == 0)
             {
                 cursorX = 3;
             }
             return true;        
        }
        else if (keyCode.compare("left") == 0)
        {
             cursorX--;
             if (cursorX < 0)
             {
                 cursorX = 0;
             }
             if (cursorY > cursorYLimit && combatStep == 1)
             {
                 cursorY = cursorYLimit;
             }
             else if (cursorY > 0 && combatStep == 0)
             {
                 cursorY = 0;
             }
             return true;        
        }
        else if (keyCode.compare("enter") == 0 || keyCode.compare(" ") == 0)
        {
             if (combatStep == 1)
             {
                enemyLibrary[enemyAtID].action (cursorX, cursorY);
                rectfill(screen, 0, 100, screen->w, screen->h, 0);
                setMessage(enemyLibrary[enemyAtID].response(cursorX, cursorY));
                combatStep = -5;
                
             }
             else if (combatStep == 0)
             {
                switch (cursorX)
                {
                       case 0:
                            combatStep = 2;
                            break;
                       case 1:
                            combatStep = 1;
                            break;
                       case 2:
                            combatStep = 3;
                            break;
                       case 3:
                            combatStep = 4;
                            break;
                }
             }
             if (combatStep == -1)
             {
                 birdYVelocity = .3;
             }  
             cursorX = 0;
             cursorY = 0;
             return true;        
        }
        else if (keyCode.compare("ctrl") == 0)
        {
             if (combatStep != -1 && combatStep != -5)
             {
                            combatStep = 0;
             }
             return true;
        }
        else if (keyCode.compare("up") == 0)
        {
             cursorY--;
             if (cursorY < 0)
             {
                 cursorY = 0;
             }
             return true;        
        }
        else if (keyCode.compare("down") == 0)
        {
             cursorY++;
             if (cursorY > cursorYLimit && combatStep == 1)
             {
                 cursorY = cursorYLimit;
             }
             return true;        
        }
        
     }
     else if (gameState == 2)
     {
        if (keyCode.compare("i") == 0 || keyCode.compare("ctrl") == 0)
        {
              gameState = 0;
        }
        else if (keyCode.compare("up") == 0)
        {    if (!itemSelected)
             {
                 cursorY--;
                 if (cursorY < 0)
                 {
                     cursorY = 0;
                 }
             }
             else if (selectorPos <= 1)
                 selectorPos--;
             return true;        
        }
        else if (keyCode.compare("down") == 0)
        {
             if (!itemSelected)
             {
                 cursorY++;
                 if (cursorY >= inventory.size())
                 {
                     cursorY = inventory.size()-1;
                 }
             }
             else if (selectorPos < 1)
                 selectorPos++;
             return true;        
        }
        else if(keyCode.compare("enter") == 0)
        {
             if (!itemSelected)
             {
                itemSelected = true;
                selectorPos = 0;
             }
             else
             {
                 if (selectorPos == 0)
                 {
                    setMessage(inventory[cursorY].getItemText());
                 }
                 if (selectorPos == 1)
                 {
                    useItem(cursorY);
                 }
                 itemSelected = false;
             }
             
        }
     }
     return false;
     
}

void Game::flappyGame(int specialEvents, BITMAP * scr, int dt)
{
     if (dt == 0)
        flappyTimer += .5;
     else
         flappyTimer += dt;
     if (flappyTimer >= 3000) 
     {
       combatStep = 0;
     }
     birdY -= birdYVelocity*(dt+1); //update x
     birdYVelocity -=  .0009; //gravity 
     
     if (frames%5 == 0)
     {
         pipe1X -= 1;
         pipe2X -= 1;
         pipe3X -= 1;
         //pipe4X -= 1;
     }
     if (pipe1X <= -2)
     {
                pipe1X = 600;
                pipe1Y = rand()%230+210;
     }
     if (pipe2X <= -2)
     {
                pipe2X = 600;
                pipe2Y = rand()%230+210;
     }
     if (pipe3X <= -2)
     {
                pipe3X = 600;
                pipe3Y = rand()%230+210;
     }

     if  ((200 >= pipe1X && 200 <= pipe1X+PIPE_WIDTH && (birdY > pipe1Y || birdY < pipe1Y-GAP_HEIGHT))||(200 >= pipe2X && 200 <= pipe2X+PIPE_WIDTH && (birdY > pipe2Y || birdY < pipe2Y-GAP_HEIGHT))||(200 >= pipe3X && 200 <= pipe3X+PIPE_WIDTH && (birdY > pipe3Y || birdY < pipe3Y-GAP_HEIGHT)))
     {
         if (flappyTimer-invTimer >= 150)
         {
               invTimer = flappyTimer;
               playerHP -= enemyLibrary[enemyAtID].getAttack();
         }
     }
     if (birdY > 390)
     {
               birdY = 380;
               playerHP -= 1;
               birdYVelocity = 0;
     }
     if (birdY < 100)
     {
               birdY = 120;
               playerHP -= 1;
               birdYVelocity = -.5;
     }        
     circle(scr, 200, (int) birdY, 10, -1);
     
     rect(scr, 50,100, 590, 400, -1); // window
     rect(scr, pipe1X, pipe1Y, pipe1X+PIPE_WIDTH, 9999999, -1);// pipe1
     rect(scr, pipe1X, pipe1Y-GAP_HEIGHT, pipe1X+PIPE_WIDTH, 0, -1);// pipe1
     
     
     rect(scr, pipe2X, pipe2Y, pipe2X+PIPE_WIDTH, 9999999, -1);// pipe2
     rect(scr, pipe2X, pipe2Y-GAP_HEIGHT, pipe2X+PIPE_WIDTH, 0, -1);// pipe2
     
     rect(scr, pipe3X, pipe3Y, pipe3X+PIPE_WIDTH, 9999999, -1);// pipe3
     rect(scr, pipe3X, pipe3Y-GAP_HEIGHT, pipe3X+PIPE_WIDTH, 0, -1);// pipe3
   
     
     frames++;
} 
void Game::setMessage(string ms)
{
     message = ms;
     displayText = "";
     drawMessageBox();
}
void Game::drawMessageBox()
{
     int messageBoxTimer = 0;
     int size = 0;
     SAMPLE *tud ;
     string line0 = "";
     string line1 = "";
     string line2 = ""; 
     tud = load_sample("tud.wav"); // or .voc
     rectfill(screen, 0, 200, 640, 480, 0); 
     while (!key[KEY_ESC] && !key[KEY_RCONTROL] && !key[KEY_LCONTROL] && size < message.size())
     {
           
           if (messageBoxTimer%500 == 0)
           {
               size++;
              if (size < 35)
              {
                 line0 = message.substr(0, size);
                 textout_hack(screen, font, 20 , 220 , 2 , line0.c_str() , -1 );
              }
              else if (size >= 35 && size < 70)
              {
                   line1 = message.substr(34, size-34);
                   textout_hack(screen, font, 20 , 320 , 2 , line1.c_str() , -1 );
              }
              else if (size >= 70)
              {
                   line2 = message.substr(70, size-70);
                   textout_hack(screen, font, 20 , 420 , 2 , line2.c_str() , -1 );
              }
              rest(30);
              play_sample(tud, 1000, 1000, 1000, 0);
           }
           
           //textout_ex(screen, font, displayText.c_str(), 20, 100, -1, 0);
           
           
           
           
           messageBoxTimer++;
     }
      size = message.size();
      if (size < 35)
      {
         line0 = message.substr(0, size);
      }
      else if (size >= 70)
      {
         line0 = message.substr(0, 34);
         line1 = message.substr(34, 34);
         line2 = message.substr(70, 34);
      }
      else if (size >= 35)
      {
         line0 = message.substr(0, 34);
         line1 = message.substr(34, 34);
       
      }
      //rectfill(screen, 0, 200, 640, 480, 0);
      textout_hack(screen, font, 20 , 220 , 2 , line0.c_str() , -1 );
      textout_hack(screen, font, 20 , 320 , 2 , line1.c_str() , -1 );
      textout_hack(screen, font, 20 , 420 , 2 , line2.c_str() , -1 );
           
     //textout_ex(screen, font, displayText.c_str(), 0, 100, -1, 0);
     while (key[KEY_ENTER] || key[KEY_Z] || key[KEY_SPACE])
     {
     }
     rest(10);
     while (!key[KEY_ESC] && !key[KEY_ENTER] && !key[KEY_Z] && !key[KEY_SPACE])
     {
         
     }
}

bool Game::drawOptionBox()
{
     int messageBoxTimer = 0;
     int size = 0;
     bool cursorPos = true;
     SAMPLE *tud ; 
    string line0 = "";
     string line1 = "";
     string line2 = ""; 
    tud = load_sample("tud.wav"); // or .voc
       rectfill(screen, 0, 200, 640, 480, 0); 
     while (!key[KEY_ESC] && !key[KEY_RCONTROL] && !key[KEY_LCONTROL] && size < message.size())
     {
            if (messageBoxTimer%500 == 0)
           {
               size++;
              if (size < 35)
              {
                 line0 = message.substr(0, size);
                 textout_hack(screen, font, 20 , 220 , 2 , line0.c_str() , -1 );
              }
              else if (size >= 35 && size < 70)
              {
                   line1 = message.substr(34, size-34);
                   textout_hack(screen, font, 20 , 320 , 2 , line1.c_str() , -1 );
              }
              else if (size >= 70)
              {
                   line2 = message.substr(70, size-70);
                   textout_hack(screen, font, 20 , 420 , 2 , line2.c_str() , -1 );
              }
              rest(30);
              play_sample(tud, 1000, 1000, 1000, 0);
           }
           
           //textout_ex(screen, font, displayText.c_str(), 20, 100, -1, 0);
           
           
           messageBoxTimer++;
     }
      size = message.size();
      if (size < 35)
      {
         line0 = message.substr(0, size);
      }
      else if (size >= 70)
      {
         line0 = message.substr(0, 34);
         line1 = message.substr(34, 34);
         line2 = message.substr(70, 34);
      }
      else if (size >= 35)
      {
         line0 = message.substr(0, 34);
         line1 = message.substr(34, 34);
       
      }
      //rectfill(screen, 0, 200, 640, 480, 0);
      textout_hack(screen, font, 20 , 220 , 2 , line0.c_str() , -1 );
      textout_hack(screen, font, 20 , 320 , 2 , line1.c_str() , -1 );
      textout_hack(screen, font, 20 , 420 , 2 , line2.c_str() , -1 );
           
     while (key[KEY_ENTER] || key[KEY_Z] || key[KEY_SPACE])
     {
     }
     rest(50);
     while (!key[KEY_ESC] && !key[KEY_ENTER] && !key[KEY_Z] && !key[KEY_SPACE])
     {
     	   int aCol = gold;
	  	   int bCol = 0;
	  	   if (!cursorPos)
	  	   {
	  	   	  bCol = gold;
	  	   	  aCol = 0;
		   }
		   if (key[KEY_LEFT])
		   {
  	  	   	  cursorPos = true;
  	  	   	  //rectfill(screen,  0, 440, 300-20, 480, aCol );
 	          //rectfill(screen,  320, 440, 600, 480, bCol );
           }
 		   else if (key[KEY_RIGHT])
 		   {
  	  	   	  cursorPos = false;
  	  	   	  //rectfill(screen,  0, 440, 300-20, 480, aCol );
 	          //rectfill(screen,  300, 440, 600, 480, bCol );
           }
	  	   //textout_ex(screen, font, optionA.c_str(), 0, 150, -1, aCol);
	  	   //rectfill(screen,  20, 440, 300, 480, aCol );
	  	   textout_hack(screen, font, 20 , 450 , 2 , optionA.c_str() , -1 , aCol);
	  	   //rectfill(screen,  320, 440, 600, 480, bCol );
	  	   textout_hack(screen, font, 300 , 450 , 2 , optionB.c_str() , -1, bCol );
	  	   //textout_ex(screen, font, optionB.c_str(), 80, 150, -1, bCol);
	  	   
     }
     return cursorPos;
     
}


bool Game::setOption(string ms, string a, string b)
{
     message = ms;
     optionA = a;
     optionB = b;
     displayText = "";
     return drawOptionBox();
}



bool Game::saveToFile()
{
	  ofstream myfile;
	  myfile.open ("save.txt", ios::trunc);
	  myfile << roomNumber;
	  myfile << " ";//IF YOU DON'T PUT IN THE SPACE IT WILL BLOW UP AND NOBODY WILL LOVE YOU!
	  myfile << karmaPoints;
	  myfile << " ";
	  myfile << world.getHat();
	  myfile << " ";
	  myfile << interactedWith[0];
      myfile << " ";
      myfile << interactedWith[1];
      myfile << " ";
      myfile << interactedWith[2];
      myfile << " ";
      myfile << interactedWith[3];
      myfile << " ";
      myfile << interactedWith[4];
      myfile << " ";
	  myfile << inventory.size();
      for (int l = 0; l < inventory.size(); l++)
      {                     
           myfile << " ";          
       	   myfile << inventory[l].getID();               
      }  
	  
	  myfile.close();
	  return false;
}
bool Game::loadFromFile()
{
  ifstream infile("save.txt");
  int invSize = 0;
     while (!infile.eof())
     {       
             infile >> roomNumber;
             infile >> karmaPoints; 
             infile >> hat; 
             infile >> interactedWith[0]; 
             infile >> interactedWith[1];
             infile >> interactedWith[2]; 
             infile >> interactedWith[3];
             infile >> interactedWith[4]; 
             infile >> invSize;
              for (int l = 0; l < invSize; l++)
              {              
                    int tempID = -1;                         
               	    infile >>  tempID;
                    forceToInventory(tempID);              
              } 
     }
     infile.close();
     world.setHat(hat);
  return false;
}
void Game::drawInventory(BITMAP* drawMe)
{
 	 rectfill(drawMe, getCamX(), getCamY(), getCamX()+(screen->w/2), getCamY()+screen->h, 0 );
 	 for (int i = 0; i < inventory.size(); i++)
 	 {
         if (i == cursorY)
            textout_ex(drawMe, font,inventory[i].getName().c_str(), getCamX()+50, getCamY()+i*50+20, -1, gold);
         else
            textout_ex(drawMe, font,inventory[i].getName().c_str(), getCamX()+50, getCamY()+i*50+20, -1, 0);
     }
     if (itemSelected)
     {
         if (selectorPos == 0)
         {
               textout_ex(drawMe, font, "Examine", getCamX()+50, getCamY()+450, -1, gold);      
                textout_ex(drawMe, font,"Use", getCamX()+50, getCamY()+470, -1, 0);       
         }
         else
         {
               textout_ex(drawMe, font, "Examine", getCamX()+50, getCamY()+450, -1, 0);      
                textout_ex(drawMe, font,"Use", getCamX()+50, getCamY()+470, -1, gold);       
         }         
     }
}
bool Game::addToInventory(int ID)
{
     if (inventory.size() >= INVCAP)
        return false;
     else
     {
         forceToInventory(ID);
     }
}  
bool Game::forceToInventory(int ID)
{

         switch (ID)
         {
                case 0:
                {
                     Item candy ("Candy", "it's blue, round, and hard. I bet it's delicious.", "Tastes like raspberry... you were healed for 15 HP", 1, 15,ID);
			         inventory.push_back(candy);
			         break;
                }
                case 1:
                {     
                     Item propellerHat ("propeller Hat", "The spinning propeller is fun and joyful", "you don your new hat with a deep sense of pride...", 3, 1, ID);
			         inventory.push_back(propellerHat);
			         break; 
                }
                case 2:
                {
                     Item santaHat ("Santa Hat", "Can you feel the religious tollerance", "you don your hat with a deep sense of yule", 3, 2, ID);
			         inventory.push_back(santaHat);
			         break;
                }
         }
}  
bool Game::useItem(int slot)
{
     switch (inventory[slot].getType())
     {
            case 1: // food items
            {     
                  playerHP +=  inventory[slot].getValue();
                  if (playerHP > playerHPCap)
                     playerHP = playerHPCap;
                  break;
            }
            case 2:// armor
            {     
                 if (armor != -1) 
                    forceToInventory(armor); //this will add the armor to a full inventory, as the previous armor will be removed
                 armor = inventory[slot].getID();
                 break;
            }
            case 3: // hats
            {    
                 if (hat >= 1)
                    forceToInventory(hat); //this will add the hat to a full inventory, as the previous hat will be removed
                  hat = inventory[slot].getID(); 
                  world.setHat(inventory[slot].getID());
                  world.update(1);
                  break;
            }
     }     
     setMessage(inventory[slot].getUseText());
    
    vector <Item> temp;
    for (int l = 0; l < inventory.size(); l++)
    {                 
      if (l != slot)
      {               
       	 temp.push_back(inventory[l]);
      }               
    }                 								 
    inventory.swap(temp);
}

bool Game::triggers (BITMAP *draw, int dt)
{
      switch (world.getRoom())
      {
             case 0:
             {
                  if (!hasBeenTriggered[0] && world.getPlayerX() >= 450 && world.getPlayerX() <= 460)
                  {
                      setMessage("This is yet another test!");
                      hasBeenTriggered[0]  = true;
                      return true;
                  }
                  
                  break;
                  
             }
             case 1:
             {
                  if (!hasBeenTriggered[1] && world.getPlayerX() >= 450 && world.getPlayerX() <= 460)
                  {
                      setMessage("You have encountered a feral      domesticated cat! (how?!) ");
                      hasBeenTriggered[1]  = true;
                      startCombat(0);
                      while (key[KEY_ENTER] || key[KEY_Z])
                      {
                            
                      }
                      return true;
                  }
                  
                  if (!hasBeenTriggered[2] && world.getPlayerX() >= 320 && world.getPlayerX() <= 360 && world.getPlayerY() <= 30 && hat == 0)
                  {
                      setMessage("You should really get a hat       before you go...");
                      hasBeenTriggered[2]  = true;
                      return true;
                  }
                  if (!hasBeenTriggered[3] && hasBeenTriggered[2] && !(world.getPlayerX() >= 360 && world.getPlayerX() <= 350 && world.getPlayerY() <= 60) && hat == 0)
                  {
                      //setMessage("You should really get a hat       before you go...");
                      hasBeenTriggered[3]  = true;
                      return true;
                  }
                  if (hasBeenTriggered[4] && world.getPlayerX() >= 320 && world.getPlayerX() <= 360 && world.getPlayerY() <= 30 && (key[KEY_UP] || key[KEY_RIGHT]) && hat == 0)
                  {
                      //setMessage("You should really get a hat       before you go...");
                      hasBeenTriggered[4]  = false;
                  }
                  if (!hasBeenTriggered[4] && hasBeenTriggered[3] && world.getPlayerX() >= 320 && world.getPlayerX() <= 360 && world.getPlayerY() <= 60 && hat == 0)
                  {
	                      setMessage("If you're having trouble slam your face into the hat stand then press  Z or Enter");
	                      setMessage("Then press Ctrl or I to open your  inventory.");
                      hasBeenTriggered[4]  = true;
                      return true;
                  }
             }
      }
}
