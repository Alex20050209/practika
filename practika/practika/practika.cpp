
 
#include <stdafx.h> //подключение библиотек
#include <clocale> 
#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <malloc.h> 
 
using namespace std; 
using namespace System; 
using namespace System::IO; 
 
#define ENTER 13 //обозначение кнопок 
#define ESC 27 
#define UP 72 
#define DOWN 80 
#define HOME 71
#define END 79
 
int menu(int); //указание шаблонов используемых функций
void maxim(struct z*);
void spis(struct z*);
void alfalist(struct z*);
void vstavka(struct z*, char*);
void diagram(struct z*);
void kolvo(struct z*);
void hard(struct z*);
 
//char dan[7][70]={ 
// "В какую дату была потрачена наибольшая сумма денег?              ", 
// "Список клиентов купивших ветровки                                ", 
// "Алфавитный список клиентов                                       ", 
// "Клиенты купившие определённое кол-во товара                      ", 
// "Есть ли клиенты, купившие одинаковое кол-во товара разного вида? ", 
// "Диаграмма. Процентное соотношение полученных денег               ", 
// "Выход                                                            " 
//}; //задание списка вопросов - пунктов меню
 
//char BlankLine[]="                                                                   "; 
// int NC; 
struct z {
	char name[20];
	char vid[20];
	int colichestvo;
	int summa;
	char data[11];

};
struct sp { //структура для алфавитного списка
 char name[20];
 int summa;
 int colichestvo;
 struct sp* sled;
 struct sp* pred;
} *Clothes_store;
 
int main(array<System::String ^> ^args) 
 { 
 int i,n; 
 int NC; 
 char BlankLine[]="                                                                   ";  
 char dan[7][70]={ 
 "В какую дату была потрачена наибольшая сумма денег?              ", 
 "Список клиентов купивших ветровки                                ", 
 "Алфавитный список клиентов                                       ", 
 "Клиенты купившие определённое кол-во товара                      ", 
 "Есть ли клиенты, купившие одинаковое кол-во товара разного вида? ", 
 "Диаграмма. Процентное соотношение полученных денег               ", 
 "Выход                                                            " 
}; //задание списка вопросов - пунктов меню
  
 FILE *in; 
 struct z *buyers; 
 setlocale(LC_CTYPE,"Russian"); 
 Console::CursorVisible::set(false);  
 Console::BufferHeight=Console::WindowHeight; 
 Console::BufferWidth=Console::WindowWidth; 
 if((in=fopen("Clothes_store.txt","r"))==NULL) 
  { 
  printf("\nФайл Clothes_store не открыт !"); 
   getch(); exit(1); 
  } 

fscanf(in,"%d",&NC);
buyers=(struct z*)malloc(NC*sizeof(struct z));

for(i=0;i<NC;i++)
	fscanf(in,"%s%s%d%d%s",buyers[i].name,
		buyers[i].vid, &buyers[i].colichestvo, &buyers[i].summa,
		buyers[i].data);
for(i=0;i<NC;i++)
	printf("\n%-20s %-9s %7d %7d %-11s",
		buyers[i].name,
		buyers[i].vid, buyers[i].colichestvo, buyers[i].summa,
		buyers[i].data);
getch();

while(1) 
  { 
   Console::ForegroundColor=ConsoleColor::White; 
   Console::BackgroundColor=ConsoleColor::DarkGreen; 
   Console::Clear();
  Console::ForegroundColor=ConsoleColor::Black; 
  Console::BackgroundColor=ConsoleColor::White; 
  Console::CursorLeft=10; 
  Console::CursorTop=4; 
  printf(BlankLine); 
 
  for(i=0;i<7;i++) 
   { 
   Console::CursorLeft=10; 
   Console::CursorTop=i+5; 
   printf(" %s ",dan[i]); 
   } 
  Console::CursorLeft=10; 
  Console::CursorTop=12; 
  printf(BlankLine); 
 
n=menu(7); 
switch(n) { 
  case 1: maxim(buyers); break; 
  case 2: spis(buyers); break; 
  case 3: alfalist(buyers); break; 
  case 4: kolvo(buyers); break; 
  case 5: hard(buyers); break; 
  case 6: diagram(buyers); break; 
  case 7: exit(0); 
 } 
} 
return 0; 
} 
 
int menu(int n) 
{ 
char dan[7][70]={ 
 "В какую дату была потрачена наибольшая сумма денег?              ", 
 "Список клиентов купивших ветровки                                ", 
 "Алфавитный список клиентов                                       ", 
 "Клиенты купившие определённое кол-во товара                      ", 
 "Есть ли клиенты, купившие одинаковое кол-во товара разного вида? ", 
 "Диаграмма. Процентное соотношение полученных денег               ", 
 "Выход                                                            " 
}; //задание списка вопросов - пунктов меню
int y1=0,y2=n-1; 
char c=1; 
while (c!=ESC) 
 { 
 switch(c) { 
  case DOWN: y2=y1; y1++; break; 
  case UP: y2=y1; y1--; break; 
  case ENTER: return y1+1; 
  case HOME: y2 = y1; y1 = 0; break;
  case END: y2 = y1; y1 = n - 1; break;
  } 
 if(y1>n-1){y2=n-1;y1=0;} 
 if(y1<0) {y2=0;y1=n-1;} 
 Console::ForegroundColor=ConsoleColor::White; 
 Console::BackgroundColor=ConsoleColor::Green; 
 Console::CursorLeft=11; 
 Console::CursorTop=y1+5; 
 printf("%s",dan[y1]); 
 Console::ForegroundColor=ConsoleColor::Black; 
 Console::BackgroundColor=ConsoleColor::White; 
 Console::CursorLeft=11; 
 Console::CursorTop=y2+5; 
 printf("%s",dan[y2]); 
 c=getch(); 
 }  
exit(0); 
}

void maxim(struct z* buyers)
{
int i=0;
int NC;
FILE *in;
if((in=fopen("Clothes_store.txt","r"))==NULL) 
  { 
  printf("\nФайл Clothes_store не открыт !"); 
   getch(); exit(1); 
  } 

fscanf(in,"%d",&NC);
struct z best;
strcpy(best.data,buyers[0].data);
best.summa=buyers[0].summa;
for(i=1;i<NC;i++)
if (buyers[i].summa>best.summa)
{
strcpy(best.data,buyers[i].data);
best.summa=buyers[i].summa;
}
Console::ForegroundColor=ConsoleColor::Black;
Console::BackgroundColor=ConsoleColor::White;
Console::CursorLeft=10;
Console::CursorTop=15;
printf("Максимальная сумма денег: %d",best.summa);
Console::CursorLeft=10;
Console::CursorTop=16;
printf("Была потрачена: %s",best.data);
getch();
}
void spis(struct z* buyers)
{
 int i = 0;
 char vid;
 int NC;
FILE *in;
if((in=fopen("Clothes_store.txt","r"))==NULL) 
  { 
  printf("\nФайл Clothes_store не открыт !"); 
   getch(); exit(1); 
  } 

fscanf(in,"%d",&NC);
 Console::ForegroundColor = ConsoleColor::Black;
 Console::BackgroundColor = ConsoleColor::White;
 Console::CursorLeft = 10;
 Console::CursorTop = 14;
 for (i = 0; i < NC; i++)
 if (strcmp(buyers[i].vid, "Ветровка") == 0)
	 printf("\n Клиент %-20s Стоимость %d Вид одежды: %s", buyers[i].name, 
buyers[i].summa, buyers[i].vid);
 getch();
}

void alfalist(struct z* buyers)//алфавитный список
{
int i,x;
int NC;
FILE *in;
if((in=fopen("Clothes_store.txt","r"))==NULL) 
  { 
  printf("\nФайл Clothes_store не открыт !"); 
   getch(); exit(1); 
  } 

fscanf(in,"%d",&NC);
 struct sp* nt,*z;
 x = 3;
 Console::ForegroundColor = ConsoleColor::Black;
 Console::BackgroundColor = ConsoleColor::DarkGreen;
 Console::Clear();
 printf("\n Алфавитный список клиентов");
 printf("\n =================================================================\n");
 if (!Clothes_store)
 for (i = 0; i < NC; i++)
	vstavka(buyers, buyers[i].name);
 for (nt = Clothes_store; nt != 0; nt = nt->sled)
 {
 Console::CursorLeft = 0;
 Console::CursorTop = x + 1;
 printf(" %-20s %ld", nt->name, nt->summa);
 x += 1;
 }
 x = 3;
 Console::CursorLeft = 40;
 Console::CursorTop = 1;
 printf("Обратный алфавитный список");
 for (nt = Clothes_store; nt != 0; z = nt, nt = nt->sled);
 for (nt = z, i = 0; nt != 0; i++, nt = nt->pred)
 {
 Console::CursorLeft = 40;
 Console::CursorTop = x + 1;
 printf(" %-20s %ld", nt->name, nt->summa);
 x += 1;
 }
 getch();
}

void vstavka(struct z* buyers, char* name)
{
 int i;
 int NC;
FILE *in;
if((in=fopen("Clothes_store.txt","r"))==NULL) 
  { 
  printf("\nФайл Clothes_store не открыт !"); 
   getch(); exit(1); 
  } 

fscanf(in,"%d",&NC);
 struct sp* nov, * nt, * z = 0;
 for (nt = Clothes_store; nt != 0 && strcmp(nt->name, name) < 0; z = nt, nt = nt->sled);
 if (nt && strcmp(nt->name, name) == 0) return;
 nov = (struct sp*)malloc(sizeof(struct sp));//выделяем память под новое имя
 strcpy(nov->name, name);
 nov->sled = nt;
 nov->pred = z;
 nov->summa = 0;
 for (i = 0; i < NC; i++)
 if (strcmp(buyers[i].name, name) == 0)
 nov->summa += buyers[i].summa;
 if (!z) Clothes_store = nov;
 if (z) z->sled = nov;
 if (nt) nt->pred = nov;
 return;
}

void kolvo(struct z* buyers)
{
int i;
char b;
int NC;
FILE *in;
if((in=fopen("Clothes_store.txt","r"))==NULL) 
  { 
  printf("\nФайл Clothes_store не открыт !"); 
   getch(); exit(1); 
  } 

fscanf(in,"%d",&NC);
Console::ForegroundColor = ConsoleColor::Black;
Console::BackgroundColor = ConsoleColor::White;
Console::CursorLeft = 10;
Console::CursorTop = 15;
Console::CursorVisible::set(true);
printf("Введите кол-во товара:");
Console::CursorLeft = 10;
Console::CursorTop = 16;
scanf("%d", &b);
Console::CursorLeft = 10;
Console::CursorTop = 17;
   for (i = 1; i < NC; i++) {
       if (buyers[i].colichestvo == b) {
           Console::CursorLeft = 10;
   printf("Фио клиента:");
            printf("%-20s", buyers[i].name);
            Console::CursorTop += 1;
            Console::CursorVisible::set(false);
        }
    }
    getch();
}

void diagram(struct z* buyers)
{
 struct sp *nt;
 int NC;
FILE *in;
if((in=fopen("Clothes_store.txt","r"))==NULL) 
  { 
  printf("\nФайл Clothes_store не открыт !"); 
   getch(); exit(1); 
  } 

fscanf(in,"%d",&NC);
 int len, i, NColor;
 long sum = 0;
 char str1[20];//переменная для имени
 char str2[20];//переменная для процентов
 System::ConsoleColor Color;
 Console::ForegroundColor = ConsoleColor::Black;//цвет текста
 Console::BackgroundColor = ConsoleColor::White;//цвет фона
 Console::Clear();
 for (i = 0; i < NC; i++)
 sum = sum + buyers[i].summa;
 if (!Clothes_store)//если список не существует то создаем его
 for (i = 0; i < NC; i++)
 vstavka(buyers, buyers[i].name);
 Color=ConsoleColor::Black;
 NColor = 0;// устанавливаем переменную цвета на 0 (чёрный)
 for (nt = Clothes_store, i = 0; nt != 0; nt = nt->sled, i++)
 {
 sprintf(str1,"%s", nt->name);//pаписываем в первую переменную имя
 sprintf(str2, "%3.1f%%", (nt->summa *100./ sum));//во вторую переменную записываем процент
 Console::ForegroundColor = ConsoleColor::DarkGreen;
 Console::BackgroundColor = ConsoleColor::White;
 Console::CursorLeft = 5;//усланавливаем положение курсора и выводим имя
 Console::CursorTop = i + 1;
 printf(str1);
 Console::CursorLeft = 20;
 printf("%s", str2);
 Console::BackgroundColor = ++Color; NColor++;
 Console::CursorLeft = 30;
 for (len = 0; len < nt->summa * 100 / sum; len++) printf(" ");
 if (NColor == 14)//если цвет курсора белый то устанавливаем на черный
 {
 Color = ConsoleColor::Black; 
 NColor = 0;
 }
 }
 getch();
 return;
 }

void hard(struct z *buyers)
{
int i,x,n=0;
int NC;
FILE *in;
if((in=fopen("Clothes_store.txt","r"))==NULL) 
  { 
  printf("\nФайл Clothes_store не открыт !"); 
   getch(); exit(1); 
  } 

fscanf(in,"%d",&NC);
for(i=0;i<NC;i++){
 for(x=1;x<NC;x++){
  if ((buyers[i].colichestvo==buyers[x].colichestvo) && (strcmp(buyers[i].vid,buyers[x].vid)!=0)){
   Console::BackgroundColor=ConsoleColor::White;
   Console::ForegroundColor=ConsoleColor::Black;
   Console::CursorLeft=10;
   Console::CursorTop=15;
   printf("Клиенты %s и %s имеют одинаковое кол-во товара: %d ",buyers[i].name,buyers[x].name,buyers[x].colichestvo);
   Console::CursorLeft=10;
   Console::CursorTop=16;
   printf("и имеют разный тип товара: %s и %s",buyers[i].vid,buyers[x].vid);
   n=1;
   break;
  }
 }
 if(n==1)
  break;
}
if(n!=1){
 Console::BackgroundColor=ConsoleColor::White;
 Console::ForegroundColor=ConsoleColor::Black;
 Console::CursorLeft=10;
 Console::CursorTop=15;
 printf("Совпадений нет!");
}
getch();
}