//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
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

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    ProgressBar1->StepIt();
    if (ProgressBar1->Position == 100)
    {
        Timer1->Enabled = false;
        Form1->Visible = false;
        Form2->Visible = true;
        //if (Form2->Enabled == false)
        //{
        //    Form1->Close();
        //}
    }
}

//---------------------------------------------------------------------------


