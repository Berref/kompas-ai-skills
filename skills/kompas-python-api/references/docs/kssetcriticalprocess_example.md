# ksSetCriticalProcess - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
reference pObj;

RequestInfo info;

double x, y;

memset(&info, 0, sizeof(info));

info.prompt = "Укажите объект";

int j =1;

while(j) {

if(YesNo("Включить критический режим?")==1)

ksSetCriticalProcess ();

j = Cursor(&info, &x ,&y, 0);

if(j && ExistObj(pObj = FindObj(x, y, 1e6))){

LightObj(pObj, 1);

Message("Выделили объект");

LightObj(pObj, 0);

}

int rez = ReturnResult();

Message(rez == etLibraryClose ? "принудительное завершение выполнения библиотеки"

: "Это не принудительное завершение");

if (rez != etLibraryClose)

j = YesNo("Продолжать?")==1;

}
