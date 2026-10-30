# GetSignPosition - Получить координаты точки привязки знака на линии выноски

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Элементы обозначений ](bb2348381.html) > [Интерфейс ILeader ](ileader.html) > [ILeader - методы](ileader_methods.html) |  Scroll [ [ [ ](ileader_setsignposition.html "К следующему разделу")](ileader_methods.html "На уровень выше")](ileader_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ileader.html)

Синтаксис Automation:

BOOL GetSignPosition( long BranchIndex, double * X, double * Y );

Синтаксис COM:

HRESULT GetSignPosition( long BranchIndex, double * X, double * Y, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

BranchIndex | \- индекс ответвления.  
---|---  
  
Выходные параметры:

X, Y | \- координаты точки привязки.  
---|---  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
