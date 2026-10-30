# SetGabaritModifying - Сообщить окну документа, что библиотека меняет габарит документа

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [Интерфейс IDocumentFrame ](idocumentframe.html) > [IDocumentFrame - методы ](idocumentframe_methods.html) |  Scroll [ [ [ ](idocumentframe_setzoomscale.html "К следующему разделу")](idocumentframe_methods.html "На уровень выше")](idocumentframe_refreshwindow.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idocumentframe.html)

Синтаксис Automation:

void SetGabaritModifying();

Синтаксис COM:

SetGabaritModifying();

Примечание:

Использование метода может понадобиться для собственного рисования в окне. Если габарит изменен, то это приведет к генерации события frAddGabarit (определение габаритов документа) из [ksDocumentFrameNotify](ksdocumentframenotify.html). В обработчике события frAddGabarit библиотека может указать свой габаритный прямоугольник, если документ является чертежом или фрагментом или свой габаритный куб, если документ является моделью. Значение габарита библиотеки сложится с габаритом документа.

Подразделы:

(отсутствуют)
