# BeginEdit - Войти в режим редактирования эскиза

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Эскиз ](bc2287727.html) > [Интерфейс ISketch ](isketch.html) > [ISketch - методы ](isketch_methods.html) |  Scroll [ [ [ ](isketch_begineditex.html "К следующему разделу")](isketch_methods.html "На уровень выше")](isketch_addsketch.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isketch.html)

Синтаксис Automation:

BeginEdit();

Возвращаемое значение:

SketchDoc | \- указатель на интерфейс [IFragmentDocument](ifragmentdocument.html).  
---|---  
  
Синтаксис COM:

HRESULT BeginEdit( [out, retval] IFragmentDocument ** SketchDoc );

Возвращаемое значение:

SketchDoc | \- указатель на интерфейс [IFragmentDocument](ifragmentdocument.html).  
---|---  
  
Примечание:

После редактирования необходимо вызвать функцию [ISketch::EndEdit](isketch_endedit.html).

Подразделы:

(отсутствуют)
