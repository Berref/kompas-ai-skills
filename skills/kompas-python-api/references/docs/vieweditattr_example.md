# ViewEditAttr - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
void ViewEditAttr_Example (void) {

// поиск объектов по значению атрибута

double x, y;

//найдем объект

int j;

reference pObj;

RequestInfo info;

memset(&info, 0, sizeof(info));

info.prompt = "Укажите объект";

do {

j = Cursor(&info, &x, &y, 0, 0);

if (j) {

if(ExistObj(pObj = FindObj(x, y, MAXDOUBLE))){

//создадим итератор для движения по атрибутам с ключом 10

reference iter = CreateAttrIterator(pObj, 10, 0,0,0,0);

LightObj(pObj, 1); //подсветили объект

// позиционировались на первый атрибут

reference pAttr = MoveAttrIterator( iter, 'F', 0);

if (pAttr) {

do {

// выдать параметры атрибута

ViewEditAttr (pAttr, 1, 0);

// на следующий атрибут

pAttr = MoveAttrIterator( iter, 'N', 0);

} while(pAttr);

}

LightObj(pObj, 0); //выключим подсветку

DeleteIterator(iter);

}

}

}while(j);

}; /* ViewEditAttr */
