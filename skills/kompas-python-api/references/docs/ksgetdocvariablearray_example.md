# ksGetDocVariableArray, ksSetDocVariableArray - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//получим указатель на текущий графический документ

reference doc = ksGetCurrentDocument(1); // 0 - любой документ,

// 1- только графический документ

// 2 - только спецификацию

if (doc)

{

char buf [250];

//получить массив внешних переменных документа

reference arrayVar = ksGetDocVariableArray(doc); //указатель на документ

//или вставку фрагмента

for (int i=0, count = GetArrayCount(arrayVar); i < count; i)

{

VariableParam par;

//получить текущую переменную

GetArrayItem(arrayVar, i, &par, sizeof(VariableParam));

sprintf(buf, "имя = %s\nзначение = %f\nкомментарий = %s", par.name, par.value, par.note);

Message(buf);

par.value = 100;

strcat(par.note, "!!!");

//заменить текущую переменную в массиве

SetArrayItem(arrayVar, i, &par, sizeof(VariableParam));

}

//заменить значения внешних переменных документа

ksSetDocVariableArray (doc, // указатель на документ или вставку фрагмента

arrayVar, // указатель на динамический массив VARIABLE_ARR

1); // комментарии менять

}

else

Error ("Документ должен быть графическим");
