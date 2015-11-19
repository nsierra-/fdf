#ifndef FDF_H
# define FDF_H

# define USAGE_STR "Usage ./fdf file"
# define EMSG_FILE "An error occured while loading file. Terminate."
# define EMSG_TERMINATE "Terminate."
# define EMSG_MALLOC "Malloc wasn't able to allocate enough memory."
# define EMSG_ENDING_LINE_LOAD "Stopping map loading."
# define EMSG_INVALID_LINE_WIDTH "A line has not the same length as the others."
# define EMSG_INVALID_NUMBER "A number is invalid."
# define EMSG_EMPTY_LIST "File seems to be invalid."

# include "ftlst.h"

typedef struct	s_data
{
	t_lst		*file_lines;
	int			**map;
	size_t		h;
	size_t		w;
}				t_data;

int				load_map(t_data *data);
int				render(t_data *data);

#endif
