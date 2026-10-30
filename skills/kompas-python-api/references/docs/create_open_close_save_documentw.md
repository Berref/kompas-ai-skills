# Пример использования функций работы с документами, Unicode

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void Document_Example (void) {

reference pDoc;

DocumentParamW doc, doc1;

char buf[ 128 ];

wcscpy( doc.fileName, _T("c:\\\gr\\\2.cad"));

wcscpy( doc.comment, _T("Чертеж"));

wcscpy( doc.author, _T("Иванов"));

doc.regim=0; //видимый режим

doc.type=1; doc.stPar.Toleranceat=3; doc.stPar.multiply=1;

doc.stPar.direct=0; doc.stPar.shtType=1;

pDoc = CreateDocumentW (&doc);

// создадим вид с номером 2

ViewParamW par;

int number = 2;

par.x = 10; par.y = 20; par.scale = 2; par.ang = 45;

par.color = RGB(10,20,10);

par.state = stACTIVE; // вид будет активным

wcscpy(par.name,_T(" пользовательский вид"));

CreateSheetViewW(&par, &number);

//создать и перейти в слой 5

Layer(5);

LineSeg(20, 10, 40, 10, 1);

LineSeg(40, 10, 40, 30, 1);

LineSeg(40, 30, 20, 30, 1);

LineSeg(20, 30, 20, 10, 1);

SaveDocument( pDoc, 0 ); //сохранить документ

CloseDocument( pDoc ); //закрыть документ

//откроем созданный документ «с:\gr\2.cad» в видимом режиме отображения

OpenDocument( "с:\gr\2.cad", 0);

}; /* Document_Example */
