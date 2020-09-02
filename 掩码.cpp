/* 如有侵权，请联系我 */

#include <graphics.h>
#include <conio.h>
#include <iomanip>


int main( void )
{
	int i ；
	char buff[512];
	int		x	= 0;
	int		y	= 0;
	IMAGE		img[48];
	COLORREF	c;
	for ( i = 1; i <= 49; i++ )
	{
		initgraph( 185, 149 );
		memset( buff, 0, 512 );
		sprintf( buff, _T( "E:\\背景 (1).jpg" ), i );
		loadimage( &img[i], buff, 175, 149, true );
		DWORD* p = GetImageBuffer( &img[i] );
		c = p[0];
		int	w	= img[i].getwidth();
		int	h	= img[i].getheight();
		for ( int j = 0; j <= 26075; j++ )
			if ( c == p[j] )
				p[j] = WHITE;
			else p[j] = BLACK;
		putimage( x, y, &img[i] );
		getch();
	}
	return(0);
}
