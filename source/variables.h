#define TILE_SIZE 15
#define EASY 0
#define MEDIUM 1
#define HARD 2

sdlTouch Stylus;

uint32_t kDown;
uint32_t kHeld;

SDL_Window * 	window;
SDL_Renderer * 	renderer;
SDL_Surface *	surface;

TTF_Font* font;
TTF_Font* font48;

Mix_Chunk *son;

#define SAVEPATH "sdmc:/switch/Pixel_Shuffle_NX/"
#define SAVEFILE "Pixel_Shuffle_NX.sav"

static inline SDL_Color SDL_MakeColour(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_Color colour = {r, g, b, a};
	return colour;
}

#define WHITE		SDL_MakeColour(255, 255, 255, 255)
#define BLACK		SDL_MakeColour(0, 0, 0, 255)
#define GREY		SDL_MakeColour(100, 100, 100, 255)
#define YELLOW		SDL_MakeColour(255, 255, 0, 255)
#define RED			SDL_MakeColour(255, 0, 0, 255)

char filename[52]; // strlen(SAVEPATH) + strlen(SAVEFILE) + 1 = 52
const char* savepath;

typedef struct 
{
	char * name;
	uint8_t mode;
	bool allowed;
	bool unlocked;
	bool selected;
	bool finished;
} 
images;
images Level[81];

SDL_Color colors[420];

uint8_t colonnes, lignes;
uint8_t choix_colonne, select_colonne, number_colonne;
uint8_t niveau_courant;

uint16_t temp_colonne[15];

bool menu_mode;
bool game_mode;

bool held_mode;
bool down_mode;

int i, j;

int widthtext, widthmenu[9];

int page_courante;
int Select, Selected, Old_selected;

bool touched, pressed;

bool victory;

uint8_t succes;

uint16_t timing;
uint16_t total_check;

bool sound_played;
