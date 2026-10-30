# ksGetMacroParam - Получить параметры макроэлемента

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Составные объекты ](bt1730612.html) |  Scroll [ [ [ ](ksdocument2d_ksgetmacroplacement.html "К следующему разделу")](bt1730612.html "На уровень выше")](ksdocument2d_ksopenmacro.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [GetMacroParam](getmacroparam.html).

Синтаксис Automation:

long ksGetMacroParam (long ref, LPDISPATCH userPars);

Входные параметры:

ref | \- указатель на макроэлемент,  
---|---  
userPars | \- указатель на интерфейс [ksUserParam](ksuserparam.html).  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Дополнительные параметры редактирования предварительно задаются функцией [ksDocument2D::ksSetMacroParam](ksdocument2d_kssetmacroparam.html).

2\. При ref = 0 выдаются параметры макроэлемента, редактирование которого производится в данный момент (если таковой имеется).

3\. Способ получения пользовательских данных (userPars) должен совпадать со способом их сохранения (void*, SAFEARRAY, или [DynamicArray](ksdynamicarray.html)) через [ksDocument2D::ksSetMacroParam](ksdocument2d_kssetmacroparam.html).

•Если пользовательские данные были сохранены через SAFEARRAY (userPars), то перед их получением нужно создать SAFEARRAY соответствующего размера (размер данных можно определить при помощи [ksDocument2D::ksGetMacroParamSize](ksdocument2d_ksgetmacroparamsize.html)).

•Если пользовательские данные были сохранены через [ksUserParam::SetUserArray](ksuserparam_setuserarray.html), то перед их получением нужно создать UserArray, аналогичный по структуре используемому при сохранении, и передать его в [ksUserParam::SetUserArray](ksuserparam_setuserarray.html).

Подразделы:

(отсутствуют)
