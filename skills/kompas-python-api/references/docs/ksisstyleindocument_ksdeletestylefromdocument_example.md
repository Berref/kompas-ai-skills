# ksIsStyleInDocument, ksDeleteStyleFromDocument - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
LibStyle par; //структура параметров стиля кривой

strcpy(par.fileName, "с:\\\1.lcs") ;

par.styleNumber = 1;

par.typeAllocation = 1; //ссылка на библиотеку стилей

//проверяем, есть ли стиль в текущем документе

if (!ksIsStyleInDocument (CURVE_STYLE, &par, sizeof (par), 1)) {

Message ("Стиля в документе нет");

unsigned short tl = AddStyle (CURVE_STYLE, &par, sizeof (par), 1);

LineSeg (20, 20, 70, 20, tl);

CurveStyleParam par1;

int t = GetStyleParam (CURVE_STYLE, tl, &par1, sizeof (par1));

if (t) {

Message (par1.name);

//стиль уже должен быть

if (ksIsStyleInDocument (CURVE_STYLE, &par, sizeof (par), 1))

Message ("Стиль в документе есть");

//удалим стиль из документа

ksDeleteStyleFromDocument (CURVE_STYLE, &par, sizeof (par), 1);

}

else

Error ("ошибка");

}
