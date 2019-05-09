��/ /   A V L - T r e e . c p p :   �[IN�c6R�S�^(uz�^�veQ�S�p0
 
 / / 
 
 
 
 # i n c l u d e   " s t d a f x . h " 
 
 # i n c l u d e < i o s t r e a m > 
 
 # i n c l u d e < v e c t o r > 
 
 # i n c l u d e < a l g o r i t h m > 
 
 u s i n g   n a m e s p a c e   s t d ; 
 
 / / s a m e   a s   a v l . c p p 
 
 t e m p l a t e < c l a s s   T > 
 
 c l a s s   A V L T r e e N o d e 
 
 { 
 
 p u b l i c : 
 
 	 T   k e y ; 
 
 	 i n t   h e i g h t ; / / ؚ�^��_OBlB F 
 
 	 A V L T r e e N o d e < T >   * r c h i l d ,   * l c h i l d ,   * p a r e n t ; 
 
 	 A V L T r e e N o d e ( T   v a l u e ,   A V L T r e e N o d e < T >   * l c h i l d ,   A V L T r e e N o d e < T >   * r c h i l d ,   A V L T r e e N o d e < T >   * p a r e n t )   : 
 
 	 	 k e y ( v a l u e ) ,   l c h i l d ( l c h i l d ) ,   r c h i l d ( r c h i l d ) ,   p a r e n t ( p a r e n t ) ,   h e i g h t ( 0 )   { } 
 
 } ; 
 
 t e m p l a t e < c l a s s   T > 
 
 c l a s s   A V L T r e e 
 
 { 
 
 p r i v a t e : 
 
 	 / / A V L T r e e N o d e < T > *   _ r o o t ; 
 
 p u b l i c : 
 
 	 A V L T r e e N o d e < T > *   _ r o o t ; 
 
 	 s i z e _ t   _ s i z e ; 
 
 	 A V L T r e e ( )   : _ r o o t ( N U L L ) ,   _ s i z e ( 0 )   { } ; 
 
 	 / / ~ A V L T r e e ( ) ; 
 
 	 / / i n t   H e i g h t ( )   {   r e t u r n   r o o t - > h e i g h t ;   } / / ���Sؚ�^
 
 	 v o i d   p r e O r d e r T r a v e r s e ( )   {   c o u t   < <   " MR�^M��S�^R�"   < <   "   " ;   p r e O r d e r T r a v e r s e ( _ r o o t ) ;   c o u t   < <   e n d l ;   } 
 
 	 v o i d   I n O r d e r T r a v e r s e ( )   {   c o u t   < <   " -N�^M��S�^R�"   < <   "   " ;   I n O r d e r T r a v e r s e ( _ r o o t ) ;   c o u t   < <   e n d l ;   } 
 
 	 v o i d   p o s t O r d e r T r a v e r s e ( )   {   c o u t   < <   " T�^M��S�^R�"   < <   "   " ;   p o s t O r d e r T r a v e r s e ( _ r o o t ) ;   c o u t   < <   e n d l ;   } 
 
 
 
 	 b o o l   i n s e r t ( T   k e y )   {   r e t u r n   i n s e r t ( k e y ,   _ r o o t )   ! =   N U L L ;   } 
 
 	 / / b o o l   r e m o v e ( T   k e y )   {   r e t u r n   r e m o v e ( k e y ,   r o o t ) ;   } 
 
 p r o t e c t e d : 
 
 	 v o i d   p r e O r d e r T r a v e r s e ( A V L T r e e N o d e < T > *   p r o o t ) ; 
 
 	 v o i d   I n O r d e r T r a v e r s e ( A V L T r e e N o d e < T > *   p r o o t ) ; 
 
 	 v o i d   p o s t O r d e r T r a v e r s e ( A V L T r e e N o d e < T > *   p r o o t ) ; 
 
 	 / / �ceQ�T Rd��v�c�S
 
 	 A V L T r e e N o d e < T > *   i n s e r t ( T   k e y ,   A V L T r e e N o d e < T > *   p r o o t ) ; / / ԏ�V�ceQT���p�vMOn
 
 	 / / b o o l   r e m o v e ( T   k e y ,   A V L T r e e N o d e < T > *   p r o o t ) ; 
 
 	 / / �el� ����v
 
 	 A V L T r e e N o d e < T > *   L e f t L e f t R o t a t i o n ( A V L T r e e N o d e < T > *   p r o o t ) ; 
 
 	 A V L T r e e N o d e < T > *   L e f t R i g h t R o t a t i o n ( A V L T r e e N o d e < T > *   p r o o t ) ; 
 
 	 A V L T r e e N o d e < T > *   R i g h t R i g h t R o t a t i o n ( A V L T r e e N o d e < T > *   p r o o t ) ; 
 
 	 A V L T r e e N o d e < T > *   R i g h t L e f t R o t a t i o n ( A V L T r e e N o d e < T > *   p r o o t ) ; 
 
 	 / / �g~b�v�cMRq��TT�~
 
 	 A V L T r e e N o d e < T > *   g e t P r e v N o d e ( A V L T r e e N o d e < T > *   p r o o t )   { 
 
 	 	 w h i l e   ( p r o o t - > l c h i l d ) p r o o t   =   p r o o t - > l c h i l d ; 
 
 	 	 r e t u r n   p r o o t ; 
 
 	 } 
 
 	 A V L T r e e N o d e < T > *   g e t S u c c N o d e ( A V L T r e e N o d e < T > *   p r o o t )   { 
 
 	 	 w h i l e   ( p r o o t - > r c h i l d ) p r o o t   =   p r o o t - > r c h i l d ; 
 
 	 	 r e t u r n   p r o o t ; 
 
 	 } 
 
 	 / / �Tؚ�^	gsQ�v�Qpe
 
 	 i n t   H e i g h t ( A V L T r e e N o d e < T > *   p r o o t )   {   r e t u r n   p r o o t   = =   N U L L   ?   0   :   p r o o t - > h e i g h t ;   } 
 
 	 v o i d   u p d a t e H e i g h t ( A V L T r e e N o d e < T > *   p r o o t )   { 
 
 	 	 i f   ( p r o o t )   p r o o t - > h e i g h t   =   1   +   m a x ( H e i g h t ( p r o o t - > l c h i l d ) ,   H e i g h t ( p r o o t - > r c h i l d ) ) ; 
 
 	 } 
 
 	 v o i d   u p d a t e H e i g h t A b o v e ( A V L T r e e N o d e < T > *   p r o o t )   { 
 
 	 	 w h i l e   ( p r o o t )   { 
 
 	 	 	 u p d a t e H e i g h t ( p r o o t ) ;   p r o o t   =   p r o o t - > p a r e n t ; 
 
 	 	 } 
 
 	 } 
 
 	 / / A V L T r e e N o d e < T > * &   s e a r c h ( A V L T r e e N o d e < T > * &   p r o o t ,   T   k e y ,   A V L T r e e N o d e < T > * &   p r e v ) ; c a n   b e   r e m o v e d 
 
 } ; 
 
 t e m p l a t e < c l a s s   T > 
 
 A V L T r e e N o d e < T > *   A V L T r e e < T > : : i n s e r t ( T   k e y ,   A V L T r e e N o d e < T > *   p r o o t )   { 
 
 	 A V L T r e e N o d e < T > *   p r e v   =   N U L L ; 
 
 	 w h i l e   ( p r o o t )   { 
 
 	 	 p r e v   =   p r o o t ; 
 
 	 	 p r o o t   =   ( k e y   <   p r o o t - > k e y )   ?   p r o o t - > l c h i l d   :   p r o o t - > r c h i l d ; 
 
 	 } 
 
 	 A V L T r e e N o d e < T > *   n o d e   =   n e w   A V L T r e e N o d e < T > ( k e y ,   N U L L ,   N U L L ,   p r e v ) ; 
 
 	 i f   ( p r e v   = =   N U L L )   _ r o o t   =   n o d e ; 
 
 	 e l s e   i f   ( k e y   <   p r e v - > k e y )   p r e v - > l c h i l d   =   n o d e ; 
 
 	 e l s e   p r e v - > r c h i l d   =   n o d e ; 
 
 	 _ s i z e + + ; 
 
 	 / / u p d a t e H e i g h t A b o v e ( n o d e ) ; 
 
 	 / /  ���T
N���s^a��v^N�f�eؚ�^
 
 	 f o r   ( A V L T r e e N o d e < T > *   p   =   n o d e ;   p ;   p   =   p - > p a r e n t )   { 
 
 	 	 i f   ( H e i g h t ( p - > l c h i l d )   -   H e i g h t ( p - > r c h i l d )   > =   2 )   { 
 
 	 	 	 i f   ( H e i g h t ( p - > l c h i l d - > l c h i l d )   > =   H e i g h t ( p - > l c h i l d - > r c h i l d ) ) 
 
 	 	 	 	 L e f t L e f t R o t a t i o n ( p ) ; 
 
 	 	 	 e l s e   L e f t R i g h t R o t a t i o n ( p ) ; 
 
 	 	 	 b r e a k ; / / VyHQؚ�^
NO	g�SS
 
 	 	 } 
 
 	 	 e l s e   i f   ( H e i g h t ( p - > r c h i l d )   -   H e i g h t ( p - > l c h i l d )   > =   2 )   { 
 
 	 	 	 i f   ( H e i g h t ( p - > r c h i l d - > r c h i l d )   > =   H e i g h t ( p - > r c h i l d - > l c h i l d ) ) 
 
 	 	 	 	 R i g h t R i g h t R o t a t i o n ( p ) ; 
 
 	 	 	 e l s e   R i g h t L e f t R o t a t i o n ( p ) ; 
 
 	 	 	 b r e a k ; 
 
 	 	 } 
 
 	 	 e l s e 
 
 	 	 	 u p d a t e H e i g h t ( p ) ; / / ck8^�`�QN�f�eؚ�^
 
 	 } 
 
 	 r e t u r n   n o d e ; 
 
 } 
 
 i n t   m a i n ( ) 
 
 { 
 
 	 A V L T r e e < i n t > *   a v l t r e e   =   n e w   A V L T r e e < i n t > ; 
 
 	 v e c t o r < i n t >   a   =   {   3 , 2 , 1 , 4 , 5 , 6 , 7 , 1 6 , 1 5 , 1 4 , 1 3 , 1 2 , 1 1 , 1 0 , 8 , 9   } ; 
 
 	 f o r   ( i n t   n u m   :   a )   a v l t r e e - > i n s e r t ( n u m ) ; 
 
 	 a v l t r e e - > p r e O r d e r T r a v e r s e ( ) ; 
 
 	 a v l t r e e - > I n O r d e r T r a v e r s e ( ) ; 
 
 	 a v l t r e e - > p o s t O r d e r T r a v e r s e ( ) ; 
 
 	 / / a v l t r e e - > R i g h t R i g h t R o t a t i o n ( a v l t r e e - > _ r o o t ) ; 
 
         r e t u r n   0 ; 
 
 } 
 
 t e m p l a t e < c l a s s   T > 
 
 A V L T r e e N o d e < T > *   A V L T r e e < T > : : L e f t L e f t R o t a t i o n ( A V L T r e e N o d e < T > *   p r o o t )   { 
 
 	 i f   ( p r o o t   = =   N U L L )   r e t u r n   N U L L ; 
 
 	 A V L T r e e N o d e < T > *   y   =   p r o o t - > l c h i l d ; 
 
 	 i f   ( y   = =   N U L L )   r e t u r n   p r o o t ; / / 
N ����te
 
 
 
 	 p r o o t - > l c h i l d   =   y - > r c h i l d ; 
 
 	 i f   ( y - > r c h i l d )   y - > r c h i l d - > p a r e n t   =   p r o o t ; 
 
 
 
 	 / / ͑�cY�V�vh�\p r o o t - > p a r e n t �[MO0R�e�_0R�vh9hy 
 
 	 i f   ( p r o o t - > p a r e n t   = =   N U L L )   _ r o o t   =   y ; 
 
 	 e l s e   i f   ( p r o o t   = =   p r o o t - > p a r e n t - > l c h i l d )   p r o o t - > p a r e n t - > l c h i l d   =   y ; 
 
 	 e l s e   p r o o t - > p a r e n t - > r c h i l d   =   y ; 
 
 	 y - > p a r e n t   =   p r o o t - > p a r e n t ; 
 
 
 
 	 y - > r c h i l d   =   p r o o t ; 
 
 	 p r o o t - > p a r e n t   =   y ; 
 
 
 
 	 u p d a t e H e i g h t ( p r o o t ) ; 
 
 	 u p d a t e H e i g h t ( y ) ; 
 
 	 r e t u r n   y ; 
 
 } 
 
 t e m p l a t e < c l a s s   T > 
 
 A V L T r e e N o d e < T > *   A V L T r e e < T > : : L e f t R i g h t R o t a t i o n ( A V L T r e e N o d e < T > *   p r o o t )   { 
 
 	 R i g h t R i g h t R o t a t i o n ( p r o o t - > l c h i l d ) ; 
 
 	 r e t u r n   L e f t L e f t R o t a t i o n ( p r o o t ) ; 
 
 } 
 
 t e m p l a t e < c l a s s   T > 
 
 A V L T r e e N o d e < T > *   A V L T r e e < T > : : R i g h t R i g h t R o t a t i o n ( A V L T r e e N o d e < T > *   p r o o t )   { 
 
 	 i f   ( p r o o t   = =   N U L L )   r e t u r n   N U L L ; 
 
 	 A V L T r e e N o d e < T > *   y   =   p r o o t - > r c h i l d ; 
 
 	 i f   ( y   = =   N U L L )   r e t u r n   p r o o t ; / / 
N ����te
 
 	 p r o o t - > r c h i l d   =   y - > l c h i l d ; 
 
 	 i f   ( y - > l c h i l d )   y - > l c h i l d - > p a r e n t   =   p r o o t ; 
 
 	 / / ͑�cY�V�vh�\p r o o t - > p a r e n t �[MO0R�e�_0R�vh9hy 
 
 	 i f   ( p r o o t - > p a r e n t   = =   N U L L )   _ r o o t   =   y ; 
 
 	 e l s e   i f   ( p r o o t   = =   p r o o t - > p a r e n t - > l c h i l d )   p r o o t - > p a r e n t - > l c h i l d   =   y ; 
 
 	 e l s e   p r o o t - > p a r e n t - > r c h i l d   =   y ; 
 
 	 y - > p a r e n t   =   p r o o t - > p a r e n t ; 
 
 
 
 	 y - > l c h i l d   =   p r o o t ; 
 
 	 p r o o t - > p a r e n t   =   y ; 
 
 	 u p d a t e H e i g h t ( p r o o t ) ; 
 
 	 u p d a t e H e i g h t ( y ) ; 
 
 	 r e t u r n   y ; 
 
 } 
 
 t e m p l a t e < c l a s s   T > 
 
 A V L T r e e N o d e < T > *   A V L T r e e < T > : : R i g h t L e f t R o t a t i o n ( A V L T r e e N o d e < T > *   p r o o t )   { 
 
 	 L e f t L e f t R o t a t i o n ( p r o o t - > r c h i l d ) ; 
 
 	 r e t u r n   R i g h t R i g h t R o t a t i o n ( p r o o t ) ; 
 
 } 
 
 
 
 
 
 # d e f i n e   P a r e n t K e y ( p )   ( p - > p a r e n t = = N U L L ?   0 : p - > p a r e n t - > k e y ) 
 
 t e m p l a t e < c l a s s   T > 
 
 v o i d   A V L T r e e < T > : : p r e O r d e r T r a v e r s e ( A V L T r e e N o d e < T > *   p r o o t )   { 
 
 	 i f   ( p r o o t   ! =   N U L L )   { 
 
 	 	 c o u t   < <   p r o o t - > k e y   < <   " ( p : "   < <   P a r e n t K e y ( p r o o t )   < <   "   H : "   < <   p r o o t - > h e i g h t   < <   " ) "   < <   "   " ; 
 
 	 	 p r e O r d e r T r a v e r s e ( p r o o t - > l c h i l d ) ; 
 
 	 	 p r e O r d e r T r a v e r s e ( p r o o t - > r c h i l d ) ; 
 
 	 } 
 
 } 
 
 t e m p l a t e < c l a s s   T > 
 
 v o i d   A V L T r e e < T > : : I n O r d e r T r a v e r s e ( A V L T r e e N o d e < T > *   p r o o t )   { 
 
 	 i f   ( p r o o t   ! =   N U L L )   { 
 
 	 	 I n O r d e r T r a v e r s e ( p r o o t - > l c h i l d ) ; 
 
 	 	 c o u t   < <   p r o o t - > k e y   < < " ( p : "   < <   P a r e n t K e y ( p r o o t )   < <   "   H : "   < <   p r o o t - > h e i g h t   < <   " ) "   < <   "   " ; 
 
 	 	 I n O r d e r T r a v e r s e ( p r o o t - > r c h i l d ) ; 
 
 	 } 
 
 } 
 
 t e m p l a t e < c l a s s   T > 
 
 v o i d   A V L T r e e < T > : : p o s t O r d e r T r a v e r s e ( A V L T r e e N o d e < T > *   p r o o t )   { 
 
 	 i f   ( p r o o t   ! =   N U L L )   { 
 
 	 	 p o s t O r d e r T r a v e r s e ( p r o o t - > l c h i l d ) ; 
 
 	 	 p o s t O r d e r T r a v e r s e ( p r o o t - > r c h i l d ) ; 
 
 	 	 c o u t   < <   p r o o t - > k e y   < <   " ( p : "   < < P a r e n t K e y ( p r o o t ) < <   "   H : "   < <   p r o o t - > h e i g h t   < <   " ) "   < <   "   " ; 
 
 	 } 
 
 } 