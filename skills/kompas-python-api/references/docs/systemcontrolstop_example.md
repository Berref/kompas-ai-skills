# SystemControlStop - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
class TEskWin : public TDialog

{

public:

TEskWin(TWindow *parent);

protected:

void EvDialogCommand1();

void EvClose();

DECLARE_RESPONSE_TABLE(TEskWin);

void TEskWin::EvClose() {

TDialog::EvClose();

SystemControlStop();

}

//точка входа в библиотеку

extern "C" void far __export pascal LibraryEntry (unsigned int)

{

TWindow *parent = GetWindowPtr((HWND)GetHWindow());

if (parent)

{

TEskWin *eskw = new TEskWin(parent);

eskw->Create(); //немодальный диалог

SystemControlStart("Остановить ESK");

//в это место библиотеки вернемся только после выполнения SystemControlStop();

delete eskw;

}

};
