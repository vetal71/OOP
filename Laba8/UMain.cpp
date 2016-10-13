//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TColorButton *new_btn;
TColorButton *array_btn[3];

//--------------------------------------------------------------------------
// Конструктор класса TColorButton
//--------------------------------------------------------------------------
__fastcall TColorButton::TColorButton(TComponent* Owner) : TSpeedButton(Owner)
{
  FColor = clBtnFace;         // цвет по умолчанию
  Transparent = false;        // прозрачность
  Width = 400;
  Height = 40;
  Flat = False;
}

//--------------------------------------------------------------------------
void __fastcall  TColorButton::DrawRaised(int Normal, int Single) {
  /*if (!Transparent)
  {
    Canvas->Pen->Color   = FColor;
    Canvas->Brush->Color = FColor;
    Canvas->Rectangle(1, 1, Width-1, Height-1);
  }

  if (Normal)
  {
    Canvas->Pen->Color = clBtnShadow;
  }
  else
  {
    Canvas->Pen->Color = clBtnHighlight;
  }
  // Толщина линии
  Canvas->Pen->Width = (Single == 1 ? 1 : 2);

  if (Normal)
  {
    Canvas->Pen->Color = clBtnHighlight;
  }
  else
  {
    Canvas->Pen->Color = clBtnShadow;
  }

  Canvas->Pen->Width = (Single == 1 ? 1 : 2);
  */
  if (!Transparent) {
    Canvas->Pen->Color = FColor;
    Canvas->Brush->Color = FColor;
    Canvas->Ellipse(1, 1, Width-1, Height-1);
  }

  if (Normal) Canvas->Pen->Color = clBtnShadow;
  else Canvas->Pen->Color = clBtnHighlight;

  Canvas->Pen->Width=(Single==1?1:2);
  Canvas->Arc(0, 0, Width, Height, 0, Height, Width, 0);

  if (Normal)  Canvas->Pen->Color = clBtnHighlight;
  else     Canvas->Pen->Color = clBtnShadow;

  Canvas->Pen->Width= (Single==1?1:2);
  Canvas->Arc(0, 0, Width, Height, Width, 0 ,0, Height);
}

//--------------------------------------------------------------------------
void __fastcall TColorButton::DrawButtonText(void) {
  TRect TextBounds(0, 0, Width, Height);
  Canvas->Brush->Style = bsClear;
  if (Enabled) {
    if (FState==bsDown)
      OffsetRect(&TextBounds, 1, 1);
    DrawText(Canvas->Handle, Caption.c_str(), Caption.Length(),
&TextBounds,
      DT_SINGLELINE + DT_CENTER + DT_VCENTER /*| BiDiMode*/);
  } else {
    OffsetRect(&TextBounds, 1, 1);
    Canvas->Font->Color = clBtnHighlight;
    DrawText(Canvas->Handle, Caption.c_str(), Caption.Length(),
&TextBounds,
      DT_SINGLELINE + DT_CENTER + DT_VCENTER /*| BiDiMode*/);
    OffsetRect(&TextBounds, -1, -1);
    Canvas->Font->Color = clBtnShadow;
    DrawText(Canvas->Handle, Caption.c_str(), Caption.Length(),
&TextBounds,
      DT_SINGLELINE + DT_CENTER + DT_VCENTER /*| BiDiMode*/);
  }
}
//--------------------------------------------------------------------------
void __fastcall TColorButton::Paint() {
  Canvas->Font = this->Font;
  Canvas->Brush->Color = Color;
  DrawRaised(1, 2);
  DrawButtonText();
 
}
//--------------------------------------------------------------------------
void __fastcall TColorButton::SetColor(TColor value)
{
  if(FColor != value) {
    FColor = value;
  }
  Invalidate();
}
//--------------------------------------------------------------------------
TColor __fastcall TColorButton::GetColor()
{
  return FColor;
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
  for(int i = 0; i < 3; i++)
    {
        array_btn[i] = new TColorButton (Form1);
        array_btn[i]->Parent = Form1;
        array_btn[i]->Top = 10 + (array_btn[i]->Height * i);
        array_btn[i]->Left = 30;
        array_btn[i]->Caption = IntToStr(i + 1) +"-я кнопка";
        array_btn[i]->OnClick = ButtonClick;
        //array_btn[i]->Color = clRed;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonClick(TObject *Sender)
{
  // Обработчик нажатия кнопки

  int red   = random(255);         // составляющая красного цвета
  int blue  = random(255);         // составляющая синего цвета
  int green = random(255);         // составляющая зеленого цвета
  TColorButton *btn = dynamic_cast<TColorButton*>(Sender);  // приведение типов TObject -> TButton
  btn->Color = (TColor)RGB(red,green,blue);     // меняем цвет фона

}
//---------------------------------------------------------------------------

/*
//  (c) Igor Azarny 2001
//  [email]azarny@hotmail.com[/email] [email]azarny@rambler.ru[/email]
//
//--------------------------------------------------------------------------
 
#ifndef CircleButtonH
#define CircleButtonH
//--------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//--------------------------------------------------------------------------
class PACKAGE TCircleButton : public TSpeedButton
{
private:
  TColor FColor;
  virtual void __fastcall DrawRaised(int Normal=1,int Single=0);
  virtual void __fastcall DrawSmooth(int Normal=1);
  virtual void __fastcall DrawButtonText(void);
  void __fastcall SetColor(TColor value);
  TColor __fastcall GetColor();
protected:
  virtual void __fastcall Paint();
public:
  __fastcall TCircleButton(TComponent* Owner);
__published:
  __property TColor Color  = { read=GetColor, write=SetColor,
default=clBtnFace };
};
//--------------------------------------------------------------------------
#endif
 
//--------------------------------------------------------------------------
 
#include <vcl.h>
#pragma hdrstop
 
#include "CircleButton.h"
#pragma package(smart_init)
//--------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//
 
static inline void ValidCtrCheck(TCircleButton *)
{
  new TCircleButton(NULL);
}
//--------------------------------------------------------------------------
__fastcall TCircleButton::TCircleButton(TComponent* Owner)
  : TSpeedButton(Owner)
{
  FColor = clBtnFace;
  Transparent = false;
}
//--------------------------------------------------------------------------
void __fastcall TCircleButton::DrawSmooth(int Normal) {
  if (!Normal) DrawRaised (Normal);
  else DrawRaised (Normal,1);
}
//--------------------------------------------------------------------------
void __fastcall  TCircleButton::DrawRaised(int Normal,int Single) {
  if (!Transparent) {
    Canvas->Pen->Color = FColor;
    Canvas->Brush->Color = FColor;
    Canvas->Ellipse(1, 1, Width-1, Height-1);
  }

  if (Normal) Canvas->Pen->Color = clBtnShadow;
  else Canvas->Pen->Color = clBtnHighlight;

  Canvas->Pen->Width=(Single==1?1:2);
  Canvas->Arc(0, 0, Width, Height, 0, Height, Width, 0);

  if (Normal)  Canvas->Pen->Color = clBtnHighlight;
  else     Canvas->Pen->Color = clBtnShadow;

  Canvas->Pen->Width= (Single==1?1:2);
  Canvas->Arc(0, 0, Width, Height, Width, 0 ,0, Height);
}
//--------------------------------------------------------------------------
void __fastcall TCircleButton::DrawButtonText(void) {
  TRect TextBounds(0, 0, Width, Height);
  Canvas->Brush->Style = bsClear;
  if (Enabled) {
    if (FState==bsDown)
      OffsetRect(&TextBounds, 1, 1);
    DrawText(Canvas->Handle, Caption.c_str(), Caption.Length(),
&TextBounds,
      DT_SINGLELINE + DT_CENTER + DT_VCENTER /);
  } else {
    OffsetRect(&TextBounds, 1, 1);
    Canvas->Font->Color = clBtnHighlight;
    DrawText(Canvas->Handle, Caption.c_str(), Caption.Length(),
&TextBounds,
      DT_SINGLELINE + DT_CENTER + DT_VCENTER /);
    OffsetRect(&TextBounds, -1, -1);
    Canvas->Font->Color = clBtnShadow;
    DrawText(Canvas->Handle, Caption.c_str(), Caption.Length(),
&TextBounds,
      DT_SINGLELINE + DT_CENTER + DT_VCENTER /);
  }
}
//--------------------------------------------------------------------------
void __fastcall TCircleButton::Paint() {
  Canvas->Font = this->Font;
  Canvas->Brush->Color = Color;
  if (Enabled) {
    if (Flat) {
      if (MouseInControl) {
        DrawRaised(FState==bsDown?0:1);
      } else {
        DrawSmooth(FState==bsDown?0:1);
      }
    } else { // not flat
      DrawRaised(FState==bsDown?0:1);
    }
  } else { // disabled   TColor
    DrawRaised(1,1);
  }
  DrawButtonText();
 
}
//--------------------------------------------------------------------------
void __fastcall TCircleButton::SetColor(TColor value)
{
  if(FColor != value) {
    FColor = value;
  }
  Invalidate();
}
//--------------------------------------------------------------------------
TColor __fastcall TCircleButton::GetColor()
{
  return FColor;
}
//--------------------------------------------------------------------------
namespace Circlebutton
{
  void __fastcall PACKAGE Register()
  {
     TComponentClass classes[1] = {__classid(TCircleButton)};
     RegisterComponents("JT", classes, 0);
  }
}
*/
