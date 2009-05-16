#ifndef SCORER_H
#define SCORER_H

struct scorer_query {
	const char *pattern;
	int right_match;
};

struct filter_result {
	int index;
	int score;
	int last_match_pos;
	int dirscore;
	int first_dir_match_pos;
};

struct prepared_pattern {
	char *translated_pattern;
	char *start_of_pattern_word;
	unsigned pat_length;
	char first_chars[8];
	char fc_count;
};

int score_string(const char *string, const struct scorer_query *query, const unsigned string_length, unsigned* match);
int score_simple_string(const char *string, const char *pattern, unsigned *match);

struct prepared_pattern *prepare_pattern(const struct scorer_query *query);
void free_prepared_pattern(struct prepared_pattern *p);

int score_string_prepared(const char *string,
			  const struct scorer_query *query,
			  const struct prepared_pattern *prepared_pattern,
			  const unsigned string_length,
			  unsigned* match);

#endif
