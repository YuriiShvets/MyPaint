
//---------------------------------------------------------------------------


#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma link "CGRID"
#pragma link "sBitBtn"
#pragma link "sTrackBar"
#pragma link "sPanel"
#pragma link "sEdit"
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        lineButtonWasClick = true;
        ellipseButtonWasClick = false;
        rectangleButtonWasClick = false;
        eraseButtonWasClick = false;
        Form1->FGShape->Brush->Color = Form1->CColorGrid1->ForegroundColor;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::lineButtonClick(TObject *Sender)
{
    lineButtonWasClick = true;
    ellipseButtonWasClick = false;
    rectangleButtonWasClick = false;
    eraseButtonWasClick = false;
}

//---------------------------------------------------------------------------

 void __fastcall TForm1::ellipseButtonClick(TObject *Sender)
{
    lineButtonWasClick = false;
    ellipseButtonWasClick = true;
    rectangleButtonWasClick = false;
    eraseButtonWasClick = false;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::rectangleButtonClick(TObject *Sender)
{
    lineButtonWasClick = false;
    ellipseButtonWasClick = false;
    rectangleButtonWasClick = true;
    eraseButtonWasClick = false;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::sTrackBar1Change(TObject *Sender)
{
        Form1->sEdit1->Text=sTrackBar1->Position;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::CColorGrid1Change(TObject *Sender)
{
    FGShape->Brush->Color = CColorGrid1->ForegroundColor;
    if (FGShape->Brush->Color == TColor(clBlack))  //
        FGShape->Pen->Color = TColor(clWhite);     //
    else                                           //changing border
        FGShape->Pen->Color = TColor(clBlack);     //

    BGShape->Brush->Color = CColorGrid1->BackgroundColor;
    if (BGShape->Brush->Color == TColor(clBlack))  //
        BGShape->Pen->Color = TColor(clWhite);     //
    else                                           //changing border
        BGShape->Pen->Color = TColor(clBlack);     //
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{

    if (Button != mbLeft)
        return;

    if (eraseButtonWasClick)
    {
        Image1->Canvas->Pen->Color = BGShape->Brush->Color;
        Image1->Canvas->Brush->Color = BGShape->Brush->Color;
        Image1->Canvas->Pen->Width = sTrackBar1->Position+10;
        Image1->Canvas->Rectangle(X-1, Y-1, X, Y);
        Image1->Canvas->MoveTo(X,Y);
        return;
    }

    InitialX = X;
    InitialY = Y;
    X1=X;
    Y1=Y;

    TmpImage = new TImage(this);
    TmpImage->Picture = Image1->Picture;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    if (!Shift.Contains(ssLeft))
        return;

    if (eraseButtonWasClick)
    {
        Image1->Canvas->LineTo(X,Y);
        return;
    }

    DrawShape(X, Y);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    if (Button != mbLeft)
        return;

    if (eraseButtonWasClick)
    {
        Image1->Canvas->Pen->Width = 1;
        return;
    }

    DrawShape(X, Y);
    delete TmpImage;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::DrawShape(int X, int Y)
{
    Image1->Picture = TmpImage->Picture;

    Image1->Canvas->Brush->Color = Form1->BGShape->Brush->Color;
    Image1->Canvas->Pen->Color = Form1->FGShape->Brush->Color;
    Image1->Canvas->Pen->Width = sTrackBar1->Position;


    if (ellipseButtonWasClick){
        Image1->Canvas->Arc(InitialX, InitialY, X, Y, X, Y, X, Y);
    }
    else if (rectangleButtonWasClick)
        {
            Image1->Canvas->Pen->Width = sTrackBar1->Position;
            Image1->Canvas->Pen->Color = Form1->FGShape->Brush->Color;
            Image1->Canvas->Brush->Style= bsClear;
            Image1->Canvas->Rectangle(InitialX, InitialY, X, Y);
        }
    else if (lineButtonWasClick)
        {
            Image1->Canvas->Pen->Width = sTrackBar1->Position;
            Image1->Canvas->MoveTo(X, Y);
            Image1->Canvas->LineTo(InitialX, InitialY);
            return;
        }
}

//---------------------------------------------------------------------------


void __fastcall TForm1::eraseButtonClick(TObject *Sender)
{
    lineButtonWasClick = false;
    ellipseButtonWasClick = false;
    rectangleButtonWasClick = false;
    eraseButtonWasClick = true;
}

//---------------------------------------------------------------------------
