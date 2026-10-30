# GetValidator - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
// Описание класса обработки диалога, в котором использованы два TEdit,

// чтобы ввести проверку интервала вводимых значений.

// К TEdit подключается валидатор

#define DIALOG_1 101

#define IDC_EDIT1 1001

#define IDC_EDIT2 1002

//-----------------------------------

// ресурс диалога

DIALOG_1 DIALOG 114, 71, 103, 107

STYLE DS_MODALFRAME | WS_POPUP | WS_VISIBLE | WS_CAPTION | WS_SYSMENU

CAPTION "Диалог"

FONT 8, "MS Sans Serif"

{

DEFPUSHBUTTON "OK", IDOK, 27, 80, 50, 14

EDITTEXT IDC_EDIT1, 63, 24, 21, 12

LTEXT "Исполнение", -1, 15, 27, 43, 8

EDITTEXT IDC_EDIT2, 63, 48, 32, 12

LTEXT "Длина", -1, 17, 50, 29, 8

}

//-----------------------------------

class TestDialog : public TDialog

{

float len;

int ispoln;

TEdit *hLen; //ввод длины: значение кладется в len

TEdit *hIspoln; //ввод исполнения: значение кладется в ispoln

public:

TestDialog (TWindow *ptParent);

void SetupWindow();

protected :

void EvLen();

void EvIspoln();

void CmOk(); // IDOK

DECLARE_RESPONSE_TABLE(TestDialog);

};

DEFINE_RESPONSE_TABLE1(TestDialog, TDialog)

EV_EN_KILLFOCUS (IDC_EDIT2, EvLen),

EV_EN_KILLFOCUS (IDC_EDIT1, EvIspoln),

EV_COMMAND(IDOK, CmOk),

END_RESPONSE_TABLE;

//конструктор диалога

//-----------------------------------

TestDialog::TestDialog(TWindow *ptParent):

TDialog(ptParent , DIALOG_1, module),

len(20),

ispoln (1)

{

hLen = new TEdit(this, IDC_EDIT2, 10);

//интервал для float: тип 4; min=0 max=100

float minF=0, maxF=100;

//валидатор контролирует значения типа float

hLen->SetValidator ((TValidator *) GetValidator(&minF, &maxF, 4));

hIspoln = new TEdit (this, IDC_EDIT1, 10);

//интервал для int: тип 2; min=1 max=5

//валидатор контролирует значения типа int

int minI =1, maxI=5;

hIspoln->SetValidator ((TValidator *) GetValidator (&minI, &maxI, 2));

};

//-----------------------------------

void TestDialog::SetupWindow()

{

char s[128];

TDialog::SetupWindow();

sprintf (s, "%.1f", len);

hLen->SetText(s);

sprintf (s, "%d", ispoln);

hIspoln->SetText(s);

}

//-----------------------------------

void TestDialog::EvLen()

{

if (hLen->IsValid(FALSE)) //мы в интервале

{

char buf[20];

char *c;

GetDlgItemText (IDC_EDIT2, buf, 10);

len = strtod (buf, &c);

}

}

//-----------------------------------

void TestDialog::EvIspoln()

{

if (hIspoln->IsValid(FALSE)) //мы в интервале

{

char buf[20];

char *c;

GetDlgItemText (IDC_EDIT1, buf, 10);

ispoln = (int) strtol (buf, &c, 10);

}

}

//-----------------------------------

void TestDialog::CmOk()

{

if (!hLen->IsValid(TRUE))

{

hLen->SetFocus();

return;

}

if (!hIspoln->IsValid(TRUE))

{

hIspoln->SetFocus();

return;

}

TDialog::CmOk();

char buf[128];

sprintf (buf, "len=%.3f ispoln=%d",len,ispoln);

Message (buf);

}

//--------------------------------------------------------------------------------

// Функция вызова диалога с использованием валидаторов

//--------------------------------------------------------------------------------

void TestValidator()

{

TestDialog *pDialog;

pDialog = new TestDialog (GetWindowPtr((HWND)GetHWindow()));

pDialog->Execute();

delete pDialog;

}
