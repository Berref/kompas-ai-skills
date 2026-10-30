//---------------------------------------------------------------------------

#ifndef blprjH
#define blprjH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>


//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TButton *btLoadGraphic;
        TButton *btUnloadGraphic;
        TButton *btLoadFile;
        TOpenDialog *OpenDialog1;
        TButton *btCloseFile;
        TButton *btNewFile;
        TButton *btSaveFile;
        TButton *btLoadLibrary;
        TButton *btRunLibraryCommand;
        TButton *btUnloadLibrary;
        TButton *btQuitWOUnload;
        TButton *btQuitUnload;
        TButton *ExecuteCommand;
  TButton *btActive;
  TButton *btVisible;
        void __fastcall btLoadGraphicClick(TObject *Sender);
        void __fastcall btUnloadGraphicClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall btLoadFileClick(TObject *Sender);
        void __fastcall btCloseFileClick(TObject *Sender);
        void __fastcall btNewFileClick(TObject *Sender);
        void __fastcall btSaveFileClick(TObject *Sender);
        void __fastcall btLoadLibraryClick(TObject *Sender);
        void __fastcall btRunLibraryCommandClick(TObject *Sender);
        void __fastcall btUnloadLibraryClick(TObject *Sender);
        void __fastcall btQuitWOUnloadClick(TObject *Sender);
        void __fastcall btQuitUnloadClick(TObject *Sender);
        void __fastcall ExecuteCommandClick(TObject *Sender);
  void __fastcall btActiveClick(TObject *Sender);
  void __fastcall btVisibleClick(TObject *Sender);
private:	// User declarations

public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
