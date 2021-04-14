// O(n) time | O(k) space. n == number of competitions, k == number of teams
function tournamentWinner(competitions, results) {
  const points = {};
  const winningTeam = { name: "", points: 0 };

  for (let i = 0; i < competitions.length; i++) {
    const match = competitions[i];
    const winningTeamIndex = results[i];
    const actualIndex = winningTeamIndex === 0 ? 1 : 0;
    const winner = match[actualIndex];

    if (winner in points) {
      points[winner] += 3;
    } else {
      points[winner] = 3;
    }

    if (winningTeam.points < points[winner]) {
      winningTeam.name = winner;
      winningTeam.points = points[winner];
    }
  }

  return winningTeam.name;
}
