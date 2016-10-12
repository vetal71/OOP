//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  // ќбработчик нажати€ кнопки
  int red   = random(255);         // составл€юща€ красного цвета
  int blue  = random(255);         // составл€юща€ синего цвета
  int green = random(255);         // составл€юща€ зеленого цвета
  TButton *btn = dynamic_cast<TButton*>(Sender);  // приведение типов TObject -> TButton
  Form1->Color = (TColor)RGB(red,green,blue);     // мен€ем цвет фона
}
//---------------------------------------------------------------------------
