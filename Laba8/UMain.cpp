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
  // ���������� ������� ������
  int red   = random(255);         // ������������ �������� �����
  int blue  = random(255);         // ������������ ������ �����
  int green = random(255);         // ������������ �������� �����
  TButton *btn = dynamic_cast<TButton*>(Sender);  // ���������� ����� TObject -> TButton
  Form1->Color = (TColor)RGB(red,green,blue);     // ������ ���� ����
}
//---------------------------------------------------------------------------
