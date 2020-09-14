SOCKET tcp_server( char *hname, char *sname )
{
	struct sockaddr_in local;
	SOCKET s;
	const int on = 1;
	set_address( hname, sname, &local, "tcp" );
	s = socket( AF_INET, SOCK_STREAM, 0 );
	if ( !isvalidsock( s ) )
		error( 1, errno, "ошибка вызова socket" );
	if ( setsockopt( s, SOL_SOCKET, SO_REUSEADDR,
		( char * )&on, sizeof( on ) ) )
		error( 1, errno, "ошибка вызова setsockopt" );
	if ( bind( s, ( struct sockaddr * ) &local,
		 sizeof( local ) ) )
		error( 1, errno, "ошибка вызова bind" );
	if ( listen( s, NLISTEN ) )
		error( 1, errno, "ошибка вызова listen" );
	return s;
}