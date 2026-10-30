# TransformObj - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
reference pObj;

RequestInfo info;

double x, y;

memset(&info, 0, sizeof (info));

info.prompt = "Укажите объект";

reference g;

int j = Cursor (&info, &x, &y, 0);

if (j)

{

if (ExistObj (pObj = FindObj (x, y, 1e6)))

{

Mtr (-10,-10,0, 2);

TransformObj (pObj);

DeleteMtr();

}

}
