//---------------------------------------------------------------------------

#ifndef UMainH
#define UMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>

//--------------------------------------------------------------------------
class PACKAGE TColorButton : public TSpeedButton
{
private:
  TColor FColor;
  virtual void __fastcall DrawRaised(int Normal=1,int Single=0);
  virtual void __fastcall DrawButtonText(void);
  void __fastcall SetColor(TColor value);
  TColor __fastcall GetColor();
protected:
  virtual void __fastcall Paint();
public:
  __fastcall TColorButton(TComponent* Owner);
__published:
  __property TColor Color  = { read=GetColor, write=SetColor, default=clBtnFace };
};

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        void __fastcall ButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
