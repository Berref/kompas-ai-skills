////////////////////////////////////////////////////////////////////////////////
//
// UserSymbol.h - класс пользовательского обозначения
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _USERSYMBOL_H
#define _USERSYMBOL_H

#include "PropManager\CPropMen.h"

class UserSymbol: public PropertyManagerObject
{
protected:
  double          m_x;      // Точка привязки
  double          m_y;      // Точка привязки
  double          m_endX;   // Точка конца выноски
  double          m_endY;   // Точка конца выноски
  bool            m_repeat; // Повторять процесс
  bool            m_firstPoint;
  bool            m_edit;
  bool            m_editLeader;
  IBaseLeaderPtr  m_leader; // Указатель на линию-выноску
  //IMacroObjectPtr m_macro;  // Макрообъект
  
public:
  UserSymbol(); // Конструктор
  double GetEndX() { return m_endX; }
  double GetEndY() { return m_endY; }
  void SetX( double x ) { m_x = x; }
  void SetY( double y ) { m_y = y; }
  void SetEndX( double x ) { m_endX = x; }
  void SetEndY( double y ) { m_endY = y; }
  bool GetFirstPoint() { return m_firstPoint; }
  void SetFirstPoint( bool fp ) { m_firstPoint = fp; }
  void Draw();
  void CreateMacro();
  static __declspec(dllexport) int WINAPI CallBack( int           com,                          // Номер команды
                                                    double      * x, double * y, // Координаты курсора
                                                    RequestInfo * info,                         // Параметры запроса
                                                    void        * phantom,                      // Фантом
                                                    int           dynamic );
 
 // prButtonClick - Нажатие кнопки.   
 virtual bool OnButtonClick       ( long buttonID );
 //prButtonUpdate        - Установка состояния кнопки спецпанели.
 virtual bool OnButtonUpdate      ( long buttonID, long * check, VARIANT_BOOL * _enable );
};

#endif // _USERSYMBOL_H