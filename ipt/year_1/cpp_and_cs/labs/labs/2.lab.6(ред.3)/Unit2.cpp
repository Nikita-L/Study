//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include "Unit4.h"
//#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

bool t=0;
//TStringList *ImageList = new TStringList();
int quantity = 0;
int openedimage = 0;
//AnsiString Path;
String *ImageList /*= new String[1]*/;

void __fastcall TForm2::Open1Click(TObject *Sender)
{
    quantity = 0;
    openedimage = 0;

    //TStringList *ImageList = new TStringList();

    if (OpenPictureDialog1->Execute())
    {
        if (t==1)
        {
            delete ImageList;
        }
        t=1;
        Image1->Stretch = false;
        Image1->Center = false;
        Image1->AutoSize = false;
        Image1->Height = 569;
        Image1->Width = 1297;
        //Image1->AutoSize = true;
        Image1->Picture->LoadFromFile(OpenPictureDialog1->FileName);
        Image1->AutoSize = true;
        if ((Image1->Height < 569) && (Image1->Width < 1297))
        {
            Image1->AutoSize = false;
            Image1->Height = 569;
            Image1->Width = 1297;
            Image1->Center = true;
            //ScrollBox1->SetFocus();
        }
        else
        {
            ScrollBox1->AutoSize = false;
            ScrollBox1->Height = 569;
            ScrollBox1->Width = 1297;
        }
        AnsiString Path = ExtractFilePath(OpenPictureDialog1->FileName)+"*.jpg";
        TSearchRec sr;
        int done = FindFirst( Path, faAnyFile, sr );
        while(!done)
        {
            quantity++;
            //ImageList->Add(sr.Name);
            done = FindNext(sr);
        }
        FindClose(sr);
        //openedimage = ImageList->IndexOf(ExtractFileName(OpenPictureDialog1->FileName));
        ImageList = new String[quantity];
        //String *Temp = new String[quantity]

        TSearchRec sr1;
        int done1 = FindFirst( Path, faAnyFile, sr1 );
        int ImageListNumber = 0;
        while(!done1)
        {
            ImageList[ImageListNumber]=sr1.Name;
            ImageListNumber++;
            done1 = FindNext(sr1);
        }
        FindClose(sr1);

        for (int i=0; i<quantity; i++)
        {
            if (ImageList[i] == ExtractFileName(OpenPictureDialog1->FileName))
            {
                openedimage = i;
                i=quantity;
            }
        }
    }
}


//---------------------------------------------------------------------------

void __fastcall TForm2::Save1Click(TObject *Sender)
{
    SavePictureDialog1->Execute();
    Image1->Picture->SaveToFile(SavePictureDialog1->FileName);        
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Exit1Click(TObject *Sender)
{
    //Form2->Close();
    //Form1->Close();
    //Info1->
    delete ImageList;
    Perform(WM_CLOSE,NULL,NULL);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
    Form1->Close();
    delete ImageList;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Shutdown1Click(TObject *Sender)
{
    WinExec("shutdown -s -t 0", SW_HIDE);        
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Sl1Click(TObject *Sender)
{
    WinExec("shutdown -r -t 0", SW_HIDE);        
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ScrollBox1MouseWheelUp(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
ScrollBox1->VertScrollBar->Position -= 10;
//ScrollBox1->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ScrollBox1MouseWheelDown(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
    ScrollBox1->VertScrollBar->Position += 10;
//ScrollBox1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
    if (t==0)
    {
        MessageBox(0,"There is no opened picture!","!", MB_OK | MB_ICONWARNING);
    }
    else
    {
        HANDLE fH;
        FILETIME creationTime;
        SYSTEMTIME sysTime;
        Info1->Visible = true;
        fH = CreateFile(OpenPictureDialog1->FileName.c_str(), GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
        if(fH != INVALID_HANDLE_VALUE)
        {
            GetFileTime(fH, &creationTime, 0, 0);
            FileTimeToSystemTime(&creationTime, &sysTime);
            Form3->Visible = true;
            Button1->Visible = false;
            AnsiString loaded = IntToStr(sysTime.wDay) + "." + sysTime.wMonth + "." + sysTime.wYear + " at " + sysTime.wHour + ":" + sysTime.wHour;
            Form3->Label5->Caption = loaded;
            Form3->Label3->Caption = /*ExtractFileName(ExtractFileDir(*/ExtractFileDir(OpenPictureDialog1->FileName.c_str())/*))*/;
            //Form3->Label6->Caption = OpenPictureDialog1->FileName.c_str()
            struct stati64 statbuf;
            _stati64(OpenPictureDialog1->FileName.c_str(), &statbuf);
            AnsiString size = IntToStr(statbuf.st_size) + " bytes";
            Form3->Label6->Caption = size;
            CloseHandle(fH);
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject *Sender)
{
    if (quantity == 0)
    {
    }
    else
    {
        if (t==0)
        {
            Form2->Open1->Click();
        }
        else
        {
        String s;
        if (openedimage==quantity-1)
        {
            //ImageList[quantity-2]= "112.jpg";
            s = ExtractFilePath(OpenPictureDialog1->FileName) + ImageList[0];
            OpenPictureDialog1->FileName = s;
            openedimage=0;
            AnsiString a(s);
            Image1->Picture->LoadFromFile(a);
            if ((Image1->Height < 569) && (Image1->Width < 1297))
                {
                Image1->AutoSize = false;
                Image1->Height = 569;
                Image1->Width = 1297;
                Image1->Center = true;
                //ScrollBox1->SetFocus();
            }
            else
            {
                ScrollBox1->AutoSize = false;
                ScrollBox1->Height = 569;
                ScrollBox1->Width = 1297;
            }
        }
        else
        {
            //ImageList[0]= "112.jpg";
            s = ExtractFilePath(OpenPictureDialog1->FileName)+ ImageList[openedimage+1];   //openedimage-1
            OpenPictureDialog1->FileName = s;
            openedimage++;
            AnsiString a(s);
            Image1->Picture->LoadFromFile(a);
            if ((Image1->Height < 569) && (Image1->Width < 1297))
                {
                Image1->AutoSize = false;
                Image1->Height = 569;
                Image1->Width = 1297;
                Image1->Center = true;
                //ScrollBox1->SetFocus();
            }
            else
            {
                ScrollBox1->AutoSize = false;
                ScrollBox1->Height = 569;
                ScrollBox1->Width = 1297;
            }
        }
        }
    }

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
    if (t==0)
    {
        Form2->Open1->Click();
    }
    else
    {
        String s;
        if (openedimage==0)
        {
            //ImageList[quantity-2]= "112.jpg";
            s = ExtractFilePath(OpenPictureDialog1->FileName) + ImageList[quantity-1];
            OpenPictureDialog1->FileName = s;
            openedimage=quantity-1;
            AnsiString a(s);
            Image1->Picture->LoadFromFile(a);
            if ((Image1->Height < 569) && (Image1->Width < 1297))
                {
                Image1->AutoSize = false;
                Image1->Height = 569;
                Image1->Width = 1297;
                Image1->Center = true;
                //ScrollBox1->SetFocus();
            }
            else
            {
                ScrollBox1->AutoSize = false;
                ScrollBox1->Height = 569;
                ScrollBox1->Width = 1297;
            }
        }
        else
        {
            //ImageList[0]= "112.jpg";
            s = ExtractFilePath(OpenPictureDialog1->FileName)+ ImageList[openedimage-1];   //openedimage-1
            OpenPictureDialog1->FileName = s;
            openedimage--;
            AnsiString a(s);
            Image1->Picture->LoadFromFile(a);
            if ((Image1->Height < 569) && (Image1->Width < 1297))
                {
                Image1->AutoSize = false;
                Image1->Height = 569;
                Image1->Width = 1297;
                Image1->Center = true;
                //ScrollBox1->SetFocus();
            }
            else
            {
                ScrollBox1->AutoSize = false;
                ScrollBox1->Height = 569;
                ScrollBox1->Width = 1297;
            }
        }
        //ImageList[openedimage]
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if ( Button == mbRight )
    {
        PopupMenu1->Popup(Mouse->CursorPos.x, Mouse->CursorPos.y);
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Plus1Click(TObject *Sender)
{
    ScrollBox1->AutoSize = false;
    ScrollBox1->Height = 569;
    ScrollBox1->Width = 1297;
    //Image1->Center = false;
    //Image1->Stretch = false;
    //Image1->AutoSize = true;
    if ((Image1->Height <= 569) && (Image1->Width <= 1297))
    {
        Image1->Center = false;
        Image1->AutoSize = true;
    }
    Image1->AutoSize = false;
    int h = Image1->Height;
    int w = Image1->Width;
    Image1->Height = h * 1.5;
    Image1->Width = w * 1.5;
    //Image1->Picture->LoadFromFile(OpenPictureDialog1->FileName);
    Image1->Stretch = true;

}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TForm2::Minus1Click(TObject *Sender)
{
    ScrollBox1->AutoSize = false;
    ScrollBox1->Height = 569;
    ScrollBox1->Width = 1297;
    if ((Image1->Height <= 569) && (Image1->Width <= 1297))
    {
        Image1->Center = false;
        //Image1->AutoSize = true;
    }
    Image1->AutoSize = false;
    int h = Image1->Height;
    int w = Image1->Width;
    Image1->Height = h / 1.5;
    Image1->Width = w / 1.5;
    Image1->Stretch = true;
}
//---------------------------------------------------------------------------

