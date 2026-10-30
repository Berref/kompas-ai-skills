# GetViewNumber, SheetToView, ViewToSheet пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//перенесем отрезки из текущего вида в вид номер 2

//получим номер текущего вида

int currentViewNumb = GetViewNumber(0);

reference obj;

//в текущем документе и виде создадим итератор для хождения по отрезкам

reference itObj = CreateIterator (LINESEG_OBJ, //тип поиска объекта

0); //указатель на объект

//(для движения по группе и внутри макро)

if (itObj)

{

if (ExistObj (obj = MoveIterator (itObj, 'F')))

{

do

{

LineSegParam par;

//берем параметры отрезка в системе координат текущего вида

GetObjParam (obj, &par, sizeof (LineSegParam), ALLPARAM);

//переводим координаты отрезка из вида в лист

ViewToSheet (par.x1, par.y1, &par.x1, &par.y1);

ViewToSheet(par.x2, par.y2, &par.x2, &par.y2);

//открываем вид 2

OpenView (2);

//переводим координаты отрезка из листа в вид 2

SheetToView (par.x1, par.y1, &par.x1, &par.y1);

SheetToView (par.x2, par.y2, &par.x2, &par.y2);

//создаем отрезок в виде 2

LineSeg (par.x1, par.y1, par.x2, par.y2, par.style);

//возвращаемся назад в вид currentViewNumb

OpenView (currentViewNumb);

//удаляем отрезок в текущем виде

DeleteObj (obj);

}

while (ExistObj (obj = MoveIterator (itObj, 'N')));

}

}
