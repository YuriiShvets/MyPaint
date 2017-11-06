
//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H

//---------------------------------------------------------------------------

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CGRID.h"
#include "sBitBtn.hpp"
#include "sTrackBar.hpp"
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "sPanel.hpp"
#include "sEdit.hpp"

//---------------------------------------------------------------------------

class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TsBitBtn *lineButton;
        TsBitBtn *rectangleButton;
        TsBitBtn *eraseButton;
        TsBitBtn *ellipseButton;
        TsTrackBar *sTrackBar1;   //size bar
        TImage *Image1;
        TCColorGrid *CColorGrid1; //choose color
        TsPanel *sPanel1;
        TsEdit *sEdit1;           //size
        TShape *FGShape;
        TShape *BGShape;
        void __fastcall lineButtonClick(TObject *Sender);
        void __fastcall ellipseButtonClick(TObject *Sender);
        void __fastcall rectangleButtonClick(TObject *Sender);
        void __fastcall sTrackBar1Change(TObject *Sender);
        void __fastcall CColorGrid1Change(TObject *Sender);
        void __fastcall Image1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall eraseButtonClick(TObject *Sender);
private:	// User declarations

    int InitialX;
    int InitialY;
    int X1;
    int Y1;
    bool lineButtonWasClick;
    bool ellipseButtonWasClick;
    bool rectangleButtonWasClick;
    bool eraseButtonWasClick;

    TImage *TmpImage;	// User declarations

public:		// User declarations
        __fastcall TForm1(TComponent* Owner);

        void __fastcall DrawShape(int X, int Y);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
