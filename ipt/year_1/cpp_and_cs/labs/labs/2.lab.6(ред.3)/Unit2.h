//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <sys\stat.h>
//#include <iostream>
//#include <string>
//#include "string.h"
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TScrollBox *ScrollBox1;
        TImage *Image1;
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *Open1;
        TMenuItem *Save1;
        TMenuItem *Exit1;
        TMenuItem *N1;
        TMenuItem *System1;
        TMenuItem *Shutdown1;
        TMenuItem *Sl1;
        TMenuItem *N2;
        TMenuItem *Info1;
        TOpenPictureDialog *OpenPictureDialog1;
        TSavePictureDialog *SavePictureDialog1;
        TPanel *Panel1;
        TButton *Button1;
    TButton *Button2;
    TButton *Button3;
    TPopupMenu *PopupMenu1;
    TMenuItem *Size1;
    TMenuItem *Fullscreen1;
    TMenuItem *Plus1;
    TMenuItem *Minus1;
        void __fastcall Open1Click(TObject *Sender);
        void __fastcall Save1Click(TObject *Sender);
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Shutdown1Click(TObject *Sender);
        void __fastcall Sl1Click(TObject *Sender);
        void __fastcall ScrollBox1MouseWheelUp(TObject *Sender,
          TShiftState Shift, TPoint &MousePos, bool &Handled);
        void __fastcall ScrollBox1MouseWheelDown(TObject *Sender,
          TShiftState Shift, TPoint &MousePos, bool &Handled);
        void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall Plus1Click(TObject *Sender);
    void __fastcall Minus1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
