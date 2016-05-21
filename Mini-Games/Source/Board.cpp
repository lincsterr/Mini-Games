/* Lincoln Glauser 5/19/16 */
/* EEEE-346 */
#include "../Include/Board.h"


Board::Board()
	: num_rows(1), num_cols(1)
{
}

Board::Board(int r, int c)
	: num_rows(r), num_cols(c)
{

}

Board::~Board()
{
}
