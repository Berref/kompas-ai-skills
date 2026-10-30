# ksGet3dDocumentFromReference - Получить указатель на документ трехмерной модели, соответствующий присланному указателю

[API экспортных функций](export_function.html) > [Функции работы с документом-моделью ](doc_3d_fncts_common.html) |  Scroll [ [ [ ](ksgetmodellibrary.html "К следующему разделу")](doc_3d_fncts_common.html "На уровень выше")](ksget3ddocument.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksGet3dDocumentFromRef](kompasobject_ksget3ddocumentfromref.html).

Синтаксис:

LPDOCUMENT3D ksGet3dDocumentFromReference (reference doc);

Входной параметр:

doc | \- указатель на документ.  
---|---  
  
Возвращаемое значение:

указатель на документ трехмерной модели | \- в случае удачного завершения,  
---|---  
NULL | \- если такого документа нет.  
  
Подразделы:

(отсутствуют)
