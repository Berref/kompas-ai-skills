# ChoiceAttr - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
double x, y;

reference pObj;

int j;

RequestInfo info;

memset(&info, 0, sizeof(info));

info.prompt = "Укажите объект";

do

{

j = Cursor (&info, &x,&y, 0);

if (j)

{

if (ExistObj(pObj = FindObj (x, y, 1e6)))

{

LightObj (pObj, 1);

ChoiceAttr (pObj);

LightObj (pObj, 0);

}

}

}

while (j);
