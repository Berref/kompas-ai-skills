# ksGetSpcDocumentPagesCount - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//функция для декомпозирования текущей спецификации и помещения ее во фрагмент

//найдем текущий документ спецификацию

reference iDoc = CreateIterator (SPC_DOCUMENT_OBJ , 0);

if (iDoc)

{

reference pDoc = MoveIterator (iDoc, 'F');

if (pDoc)

{

do

{

int state;

if (GetObjParam (pDoc, &state, sizeof (state), DOCUMENT_STATE)

&& state == stACTIVE)

break;

pDoc = MoveIterator(iDoc, 'N');

}

while (pDoc);

}

DeleteIterator(iDoc); //указатель на итератор

if (pDoc)

{

//найдем количество листов спецификации

int pageCount = ksGetSpcDocumentPagesCount (pDoc);

//найдем габариты одного листа спецификации

RectParam spcGabarit;

GetObjGabaritRect (pDoc, &spcGabarit);

//создадим фрагмент

DocumentParam doc;

memset (&doc, 0, sizeof (doc));

doc.regim = 0;

doc.type = 3;

CreateDocument (&doc);

for (int i = 0; i < pageCount; i)

{

//получили временную группу i-го листа спецификации

reference group = DecomposeObj (pDoc, //указатель на объект

0, //уровень разбиения:

//отрезки,дуги,тексты,точки;

0.4, //стрелка прогиба

uint8(i1));// 0 - разбиение объекта

// в СК вида,

// 1- в СК листа

if (group)

{

int column=i%3;

double x = (spcGabarit.pTop.x-spcGabarit.pBot.x 5)*column;

int row = i/3;

double y = (spcGabarit.pTop.y-spcGabarit.pBot.y 5)*row;

//сдвинули группу

MoveObj (group, x, -y);

//поставили в модель

StoreTmpGroup (group); //указатель группы

ClearGroup (group);

DeleteObj(group);

}

}

char buf[128];

sprintf (buf, "Преобразовано %d листов СП", pageCount);

Message (buf);

}

else

Error("Спецификация должна быть текущей");

}
